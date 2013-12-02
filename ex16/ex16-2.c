#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight) {
  struct Person who;

  who.name = strdup(name);
  who.age = age;
  who.height = height;
  who.weight = weight;

  printf("--- '%s', from within Person_create: %p\n", who.name, &who);

  return who;
}

void Person_destroy(struct Person who) {
  free(who.name);
}

void Person_print(struct Person who) {
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {

  // make two people structures
  struct Person joe = Person_create(
      "Joe Alex", 32, 64, 140);
  printf("--- '%s', from within main: %p\n", joe.name, &joe);

  struct Person frank = Person_create(
      "Frank Blank", 20, 72, 180);
  printf("--- '%s', from within main: %p\n", frank.name, &frank);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", (void *)&joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", (void *)&frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);

  frank.age += 20;
  frank.weight += 20;
  Person_print(frank);

  // destroy them both so we clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
