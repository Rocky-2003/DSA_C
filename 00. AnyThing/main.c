#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int age;
  struct Node *next;
};

struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

int main()
{

  printf("%d\n", temp);
  printf("%d\n", *temp);

  return 0;
}