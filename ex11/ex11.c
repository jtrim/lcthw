#include <stdio.h>

int main(int argc, char *argv[]) {

  int i = 0;
  while (i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }

  char *states[] = {
    "California", "Oregon",
    "Washington", "Texas"
  };

  int num_states = 4;
  i = 0;
  while (i < num_states) {
    printf("State %d: %s\n", i, states[i]);
    i++;
  }

  printf("\nargv[1] memory position: %u\n", &argv[1]);

  states[0] = argv[1];

  printf("\nstates[0] memory position after states[0] = argv[1]: %u\n", &states[0]);

  return 0;
}
