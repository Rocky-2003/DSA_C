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

void insertAt()
{
  int totalNodes = countNodes();
  int position, age;

  printf("Enter the position where you want to add Node:\n");
  scanf("%d", &position);
  if (position <= 0 || position > totalNodes + 1)
  {
    printf("Please enter a valid poistion!\n");
    return;
  }

  printf("Enter the age:\n");
  scanf("%d", &age);
  struct Node *nodeToInsert = addNode(age);

  if (position == 1)
  {
    struct Node *temp = headNode;
    nodeToInsert->next = temp;
    nodeToInsert->prev = temp->prev;
    temp->prev->next = nodeToInsert;
    temp->prev = nodeToInsert;
    headNode = nodeToInsert;
  }
  else
  {
    struct Node *temp = headNode;
    for (int i = 1; i < position - 1; i++)
    {
      temp = temp->next;
    }

    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
  }
}

void deleteNode()
{
  int totalNodes = countNodes();
  int position;

  printf("Enter the position of node you want to delete: \n");
  scanf("%d", &position);

  if (position <= 0 || position > totalNodes)
  {
    printf("Please enter a valid Position\n");
    return;
  }
  struct Node *nodeToDelete = headNode;

  if (totalNodes == 1 && position == 1)
  {
    free(headNode);
    headNode = NULL;
  }
  else
  {
    for (int i = 1; i < position; i++)
    {
      nodeToDelete = nodeToDelete->next;
    }
    nodeToDelete->next->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    if (position == 1)
      headNode = nodeToDelete->next;
    free(nodeToDelete);
    nodeToDelete = NULL;
  }
}

void reverseList()
{

  if (headNode == NULL)
  {
    printf("List is Empty!");
  }
  else
  {

    struct Node *ptr = headNode;
    struct Node *temp;
    do
    {
      temp = ptr->prev;
      ptr->prev = ptr->next;
      ptr->next = temp;

      ptr = ptr->prev;

    } while (ptr!= headNode);

    if (temp != NULL)
    {
      headNode = temp->prev;
    }
  }
}

void addLast() {}
void update() {}

int main()
{

  int ch;
  while (1)
  {
    printf("\n 1. Add Node First");
    printf("\n 2. reverseList ");
    printf("\n 3. Insert Node at");
    printf("\n 4. Delete Node at");
    printf("\n 5. update Node at");
    printf("\n 6. Print Nodes");
    printf("\n 7. Count Nodes");
    printf("\n 8. printNodesBackward Nodes");
    printf("\n 9. Exit\n");
    printf("Enter you option: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      addFirst();
      break;
    case 2:
      reverseList();
      break;
    case 3:
      insertAt();
      break;
    case 4:
      deleteNode();
      break;
    case 5:
      update();
      break;
    case 6:
      printNodes();
    case 7:
      printf("%d", countNodes());
      break;
    case 8:
      printNodesBackward();
      break;
    case 9:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }
  return 0;
}