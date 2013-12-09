#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main(int argc, char *argv[]) {
  printf("Figuring out string pointers, dammit.\n");

  char buffer[MAX_SIZE];
  char *write_head;

  printf("Buffer is at: %p\n", buffer);

  write_head = buffer;

  printf("Write head points to: %p\n", write_head);

  printf("Are they the same?: %i\n", write_head == buffer);

  for (write_head = buffer;
       (write_head - buffer) <= MAX_SIZE - 2;
       write_head++) {
    *(write_head) = 'w';
  }

  buffer[MAX_SIZE - 1] = '\0';

  printf("Buffer: %s\n", buffer);
  printf("Size of buffer: %i\n", strlen(buffer));

  return 0;
}
