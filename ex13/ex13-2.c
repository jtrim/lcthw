#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("ERROR: You need one argument.\n");
    return 1;
  }

  int i = 0;
  for (i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];
    int char_code = (int)(letter);

    if (char_code >= 65 && char_code <= 90) {
      letter = (char)(char_code + 32);
    }

    switch(letter) {
      case 'a':
        printf("%d: 'a'\n", i);
        break;

      case 'e':
        printf("%d: 'e'\n", i);
        break;

      case 'i':
        printf("%d: 'i'\n", i);
        break;

      case 'o':
        printf("%d: 'o'\n", i);
        break;

      case 'u':
        printf("%d: 'u'\n", i);
        break;

      case 'y':
        if (i > 2) {
          printf("%d: 'y'\n", i);
        }
        break;

      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }

  return 0;
}
