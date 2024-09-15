#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{

  int rollNo;
  int age;
  struct Node *next;

  /* data */
};

struct Node *headNode = NULL;

struct Node *addElement(int rollNo, int age)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->rollNo = rollNo;
  newNode->age = age;
  newNode->next = NULL;
  return newNode;
}

void addFirst()
{
  int rollNo, age;
  struct Node *p1;
  printf("enter age\n");
  scanf("%d", &age);
  printf("enter rollNo\n");
  scanf("%d", &rollNo);
  p1 = addElement(rollNo, age);
  p1->next = headNode;
  headNode = p1;
}
void addLast()
{
  int rollNo, age;
  struct Node *p1;
  printf("enter age\n");
  scanf("%d", &age);
  printf("enter rollNo\n");
  scanf("%d", &rollNo);
  p1 = addElement(rollNo, age);
  if (headNode == NULL)
  {
    headNode = p1;
  }
  else
  {
    struct Node *temp = headNode;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = p1;
  }
}

void printElement()
{

  struct Node *temp = headNode; // headNode at the head of the list

  if (temp == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  // Traverse the list and print each Node's details
  while (temp != NULL)
  {
    printf("RollNo: %d, Age: %d\n", temp->rollNo, temp->age);
    temp = temp->next; // Move to the next node
  }
}

int main()
{
  addFirst();
  addLast();
  printElement();
  return 0;
}