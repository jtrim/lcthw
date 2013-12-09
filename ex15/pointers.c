#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("\n\n");

  char *foo = "Foo!";

  printf("foo is '%s'\n", foo);
  printf("Value at foo: %c\n", *foo);
  printf("Address is %u\n", (int)&(*foo));

  printf("\n\n");

  printf("Character at first foo: %c\n", *foo);
  printf("Character at second foo: %c\n", *(foo + 1));
  printf("Character at third foo: %c\n", *(foo + 2));
  printf("Character at fourth foo: %c\n", *(foo + 3));

  printf("\n\n");

  char *other_foo = foo;

  printf("other_foo is '%s'\n", other_foo);
  printf("Value at other_foo: %c\n", *other_foo);
  printf("Address of other_foo is %u\n", (int)&(*other_foo));

  printf("\n\nNow with a pointer to an integer.\n");

  int fiz_source = 1;
  int *fiz = &fiz_source;

  printf("fiz is %i\n", *fiz);
  printf("Address is %u\n", (int)&(*fiz));

  int *other_fiz = fiz;

  printf("Address of other_fiz is %u\n", (int)&(*other_fiz));

  return 0;
}
