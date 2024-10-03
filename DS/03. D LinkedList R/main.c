#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int age;
  struct Node *next;
  struct Node *prev;
};

struct Node *headNode = NULL;

struct Node *createNode(int age)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->age = age;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

int getInput()
{
  int age;
  printf("Enter the age: ");
  scanf("%d", &age);
  return age;
}

void addNodeFirst()
{
  int ch = 1;
  do
  {

    int age = getInput();
    struct Node *newNode = createNode(age);
    if (headNode == NULL)
    {
      headNode = newNode;
    }
    else
    {
      newNode->next = headNode;
      headNode->prev = newNode;
      headNode = newNode;
    }
    printf("Do you want to add more Node press 0, otherwise 1:  ");
    scanf("%d", &ch);
  } while (ch == 0);
}

void printNode()
{
  if (headNode == NULL)
  {
    printf("List is Empty!---\n");
    return;
  }

  if (headNode->next == NULL)
  {
    printf("Age is: %d\n", headNode->age);
  }
  else
  {
    struct Node *temp = headNode;

    while (temp != NULL)
    {
      printf("Age is: %d\n", temp->age);
      temp = temp->next;
    }
  }
}

int countNodes()
{
  int count = 1;
  if (headNode == NULL)
  {
    printf("list is Empty!\n");
    // return;
  }
  else
  {
    struct Node *temp = headNode;
    while (temp->next != NULL)
    {
      count++;
      temp = temp->next;
    }
  }
  printf("TotalNodes: %d\n", count);
  return count;
}

void reverseList()
{
  if (headNode == NULL)
  {
    printf("List is Empty!+++\n");
  }
  else
  {
    struct Node *temp;
    struct Node *listToReverse = headNode;

    while (listToReverse != NULL)
    {

      temp = listToReverse->prev;
      listToReverse->prev = listToReverse->next;
      listToReverse->next = temp;
      listToReverse = listToReverse->prev;
    }

    if (headNode != NULL)
    {

      headNode = temp->prev;
    }

    printf("List is Reverserd!\n");
  }
}

int main()
{

  addNodeFirst();
  printNode();
  // countNodes();
  reverseList();
  printNode();
  return 0;
}