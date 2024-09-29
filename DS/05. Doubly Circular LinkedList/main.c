#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{

  int age;
  // char name[10];

  struct Node *next;
  struct Node *prev;
};

struct Node *headNode = NULL;

struct Node *addNode(int age)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->age = age;
  // newNode->name = name;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

void addFirst()
{
  int ch = 1;
  do
  {

    int age;
    // char name[10];

    printf("Enter the age: \n");
    scanf("%d", &age);
    // printf("Enter the name: ");
    // scanf("%d", &name);
    struct Node *newNode = addNode(age);
    if (headNode == NULL)
    {
      newNode->next = newNode->prev = headNode = newNode;
    }
    else
    {
      newNode->next = headNode;
      newNode->prev = headNode->prev;
      headNode->prev->next = newNode;
      headNode->prev = newNode;
    }

    printf("Enter 0 for more nodes to add, otherwise 1:-  ");
    scanf("%d", &ch);
  } while (ch == 0);
}

int countNodes()
{
  if (headNode == NULL)
  {
    printf("List is Empty!\n");
    return 0;
  }

  struct Node *temp = headNode;
  int totalNodes = 1;
  while (temp->next != headNode)
  {
    temp = temp->next;
    totalNodes++;
  }
  printf("TotalNodes are: %d\n", totalNodes);
  return totalNodes;
}

void printNodes()
{
  if (headNode == NULL)
  {
    printf("List is empty!\n");
  }
  else
  {

    struct Node *temp = headNode;
    do
    {
      printf("Age is: %d\n", temp->age);
      temp = temp->next;
    } while (temp != headNode);
  }
}

void printNodesBackward()
{
  if (headNode == NULL)
  {
    printf("List is empty!\n");
  }
  else
  {

    struct Node *temp = headNode->prev;
    do
    {
      printf("Age is: %d\n", temp->age);
      temp = temp->prev;
    } while (temp != headNode->prev);
  }
}
int main()
{
  addFirst();
  countNodes();
  printNodes();
  printNodesBackward();
  return 0;
}