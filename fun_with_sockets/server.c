#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define TCP_PROTOCOL 6
#define BUFFER_SIZE 500

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(10);
  }

  struct addrinfo hints;
  struct addrinfo *result;

  memset(&hints, 0, sizeof(struct addrinfo));

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_protocol = TCP_PROTOCOL;
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  int status = getaddrinfo("0.0.0.0", argv[1], &hints, &result);

  int sock_file_descriptor;
  struct addrinfo *current_addrinfo;

  for (current_addrinfo = result;
        current_addrinfo != NULL;
        current_addrinfo = current_addrinfo->ai_next) {
        sock_file_descriptor = socket(current_addrinfo->ai_family,
                      current_addrinfo->ai_socktype,
                      current_addrinfo->ai_protocol);
    if (sock_file_descriptor < 0) {
      printf("Unable to establish a socket. Status: %i\n", sock_file_descriptor);
      exit(1);
    }

    status = bind(sock_file_descriptor, current_addrinfo->ai_addr, current_addrinfo->ai_addrlen);
    if (status != 0) {
      printf("Uanble to bind to socket.\n");
      exit(2);
    }

    break;
  }

  if (current_addrinfo == NULL) {
    printf("No address available to bind to.\n");
    exit(3);
  }

  char connected_host[NI_MAXHOST], connected_port[NI_MAXSERV];

  status = getnameinfo(current_addrinfo->ai_addr, current_addrinfo->ai_addrlen,
                        connected_host, NI_MAXHOST,
                        connected_port, NI_MAXSERV,
                        NI_NUMERICSERV);

  if (status != 0) {
    printf("Unable to determine host / port for listening. Status: %i\n", status);
    exit(5);
  }

  // addrinfo no longer needed after socket is bound
  freeaddrinfo(result);

  socklen_t peer_addr_len;
  struct sockaddr_storage peer_addr;

  char buffer[BUFFER_SIZE];
  char *write_head;
  int nread;

  status = listen(sock_file_descriptor, SOMAXCONN);

  if (status != 0) {
    perror("Unable to listen for connections");
    exit(6);
  }

  printf("Listening on %s:%s\n\n", connected_host, connected_port);

  for (;;) {
    peer_addr_len = sizeof(struct sockaddr_storage);

    int accept_file_descriptor = accept(sock_file_descriptor, (struct sockaddr *) &peer_addr, &peer_addr_len);

    if (accept_file_descriptor == -1) {
      perror("Unable to accept a connection");
      exit(7);
    }

    memset(buffer, 0, BUFFER_SIZE);

    nread = recv(accept_file_descriptor, buffer, BUFFER_SIZE, 0);

    if (nread < 0) {
      perror("Failed request");
      continue; // ignore failed request
    }

    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    status = getnameinfo((struct sockaddr *) &peer_addr,
                          peer_addr_len,
                          host, NI_MAXHOST,
                          port, NI_MAXSERV,
                          NI_NUMERICSERV);

    if (status != 0) {
      printf("Unable to determine hostname. Status: %i\n", status);
      exit(4);
    }

    printf("Received %ld bytes from %s:%s:\n", (write_head - buffer), host, port);
    printf("%s%%%%%%", buffer);

    char *response = "<p>Standard response</p>";
    write(accept_file_descriptor, response, sizeof(char) * strlen(response));

    shutdown(accept_file_descriptor, SHUT_RDWR);
    close(accept_file_descriptor);
  }

  return 0;
}
