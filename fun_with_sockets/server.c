#include <stdio.h>
#include <sys/socket.h>

#define TCP_PROTOCOL 6

int main(int argc, char *argv[]) {
  int server_socket = socket(PF_INET, SOCK_STREAM, TCP_PROTOCOL);
  // struct sockaddr server_bind_address;

  return 0;
}
