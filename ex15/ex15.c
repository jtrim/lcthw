#include <stdio.h>

int main(int argc, char *argv[]) {

  // original definition: int ages[] = { 23, 43, 12, 89, 2 };
  int ages[5];
  *(ages) = 12;
  *(ages + 1) = 43;
  *(ages + 2) = 12;
  *(ages + 3) = 89;
  *(ages + 4) = 2;


  /* original definition:
   * char *names[] = {
   *   "Alan", "Frank",
   *   "Mary", "John", "Lisa"
   * };
   */
  char *names[5];
  *(names) = "Alan";
  *(names + 1) = "Frank";
  *(names + 2) = "Mary";
  *(names + 3) = "John";
  *(names + 4) = "Lisa";

  // c
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // c
  for (i = 0; i < count; i++) {
    printf("%s has %d years alive.\n",
        names[i], ages[i]);
  }

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names;

  // ...using pointers
  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n",
        *(cur_name + i), *(cur_age + i));
  }

  printf("---\n");

  // ...pointers are just arrays
  for (i = 0; i < count; i++) {
    printf("%s is %d years old again.\n",
        cur_name[i], cur_age[i]);
  }

  printf("---\n");

  // ...with pointers in a stupid complex way
  for (cur_name = names, cur_age = ages;
      (cur_age - ages) < count;
      cur_name++, cur_age++) {
    printf("%s lived %d years so far.\n", *cur_name, *cur_age);
  }

  return 0;
}
