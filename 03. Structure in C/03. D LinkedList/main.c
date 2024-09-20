#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  int age;
  struct Node *prev;
  struct Node *next;
};

struct Node *headNode = NULL;
struct Node *createNode(int age)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->age = age;
  ptr->prev = NULL;
  ptr->next = NULL;
  return ptr;
}

void addFirst()
{
  int ch = 1;
  do
  {
    int age;
    printf("Enter age:");
    scanf("%d", &age);
    struct Node *newNode = createNode(age);
    if (headNode == NULL)
    {
      // newNode->next = headNode;
      headNode = newNode;
    }
    else
    {
      headNode->prev = newNode;
      newNode->next = headNode;
      headNode = newNode;
    }

    printf("Enter 0 for continue to add or 1 to stop: ");
    scanf("%d", &ch);
  } while (ch == 0);
}

void addLast()
{
  int ch = 1;
  do
  {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);
    struct Node *newNode = createNode(age);
    if (headNode == NULL)
    {

      headNode = newNode;
    }
    else
    {
      struct Node *temp = headNode;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }

      temp->next = newNode;
      newNode->prev = temp;
    }
    printf("Enter 0 for continue to add or 1 to stop: ");
    scanf("%d", &ch);

  } while (ch == 0);
}

int countNodes()
{
  struct Node *temp = headNode;
  int totalNodes = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    totalNodes++;
  }
  return totalNodes;
}

void printList()
{
  if (headNode == NULL)
  {
    printf("List is Empty");
    return;
  }
  else
  {
    struct Node *temp = headNode;
    while (temp != NULL)
    {

      printf("Age is: %d, prev: %d, next: %d\n", temp->age, temp->prev, temp->next);
      temp = temp->next;
    }
  }
}

void printReverse()
{
  if (headNode == NULL)
    return;
  struct Node *temp = headNode;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  while (temp != NULL)
  {
    printf("Age is: %d, Prev is: %d\n", temp->age, temp->prev);
    temp = temp->prev;
  }
}

void insertAt()
{
  int position, age;
  int totalNodes = countNodes();
  struct Node *tempHeadNode = headNode;
  printf("Enter position where you want to insert the NewNod:");
  scanf("%d", &position);
  if (position <= 0 || position > totalNodes + 1)
  {
    printf("Enter Valid Input");
    return;
  }

  printf("Enter the Age: ");
  scanf("%d", &age);
  struct Node *newNode = createNode(age);
  if (position == 1)
  {

    headNode->prev = newNode;
    newNode->next = headNode;
    headNode = newNode;
  }
  if (position == totalNodes + 1)
  {
    while (tempHeadNode->next != NULL)
    {
      tempHeadNode = tempHeadNode->next;
    }
    tempHeadNode->next = newNode;
    newNode->prev = tempHeadNode;
    return; 
  }

  int currentPosition = 1;
  while (position - 1 > currentPosition)
  {
    tempHeadNode = tempHeadNode->next;
    currentPosition++;
  }

  newNode->next = tempHeadNode->next;
  newNode->prev = tempHeadNode;
  tempHeadNode->next->prev = newNode;
  tempHeadNode->next = newNode;
}

int main()
{

  addLast();
  insertAt();
  printList();
  // printReverse();
}