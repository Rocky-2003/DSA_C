#include <stdio.h>
#include <stdlib.h>

struct node
{
  int age;
  struct node *next;
};

struct node *headNode = NULL;

struct node *addElement(int age)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->age = age;
  newNode->next = NULL;
  return newNode;
}

void getInput(int *age)
{
  printf("Enter your age: ");
  scanf("%d", age);
}

void addFirst()
{
  int res = 1;

  do
  {
    int age;
    getInput(&age);
    struct node *ptr = addElement(age);
    if (headNode == NULL)
    {
      headNode = ptr;
      headNode->next = headNode;
    }

    else if (headNode->next == headNode)
    {
      headNode->next = ptr;
      ptr->next = headNode;
    }
    else
    {
      struct node *temp = headNode;
      while (temp->next != headNode)
      {
        temp = temp->next;
      }
      temp->next = ptr;
      ptr->next = headNode;
    }

    printf("Do you want to add more nodes 0 for yes & 1 for no:");
    scanf("%d", &res);
  } while (res == 0);
}

int countLength()

{
  if (headNode == NULL)
  {
    return 0;
  }

  struct node *temp = headNode;
  if (temp->next == headNode)
  {
    return 1;
  }
  else
  {

    int count = 1;
    while (temp->next != headNode)
    {
      count++;
      temp = temp->next;
    }

    printf("Total no. of count is: %d\n", count);
    return count;
  }
}

void printElements()
{

  if (headNode == NULL)
  {
    printf("LinkedList is Empty!");
    return;
  }

  if (headNode->next == headNode)
  {
    printf("Age is: %d\n", headNode->age);
    return;
  }

  struct node *temp = headNode;
  do
  {
    printf("Age is: %d\n", temp->age);
    temp = temp->next;
  } while (temp != headNode);
}

void addLast() {};

void insertAt()
{
  if (headNode == NULL)
    return;
  int age, i, position;
  int totalNodes = countLength();
  printf("Enter position where to insert: ");
  scanf("%d", &position);

  if (position < 1 || position > totalNodes + 1)
  {
    printf("Invalid position!");
  }
  else
  {
    getInput(&age);
    struct node *ptr = addElement(age);
    if (position == 1)
    {
      struct node *temp = headNode;
      while (temp->next != headNode)
      {
        temp = temp->next;
      };
      temp->next = ptr;
      ptr->next = headNode;
      headNode = ptr;
    }
    else
    {
      struct node *temp = headNode;
      for (i = 1; i < position - 1; i++)
      {
        temp = temp->next;
      }
      if (position > totalNodes)
      {
        ptr->next = headNode;
        temp->next = ptr;
      }
      else
      {
        ptr->next = temp->next;
        temp->next = ptr;
      }
    }
  }
}

void deleteNode()
{
  int position;
  int totalNodes = countLength();
  printf("Enter the Position to Delete  Node: ");
  scanf("%d", &position);

  if (position <= 0 || position > totalNodes)
  {
    printf("Invalid Position🔥🔥🔥");
    return;
  }

  if (position == 1)
  {
    if (totalNodes == 1)
    {
      free(headNode);
      headNode = NULL;
    }
    else
    {

      struct node *lastNode = headNode;
      while (lastNode->next != headNode)
      {
        lastNode = lastNode->next;
      }
      headNode = headNode->next;
      free(lastNode->next);
      lastNode->next = headNode;
    }
  }
  else
  {
    printf("Node !=1 and totalNodes >1");
    int livePosition = 1;
    struct node *temp = headNode;
    while (position - 1 > livePosition)
    {
      temp = temp->next;
      livePosition++;
    }
    if (position == totalNodes)
    {
      struct node *nodeToDelete = temp->next;
      temp->next = headNode;
      free(nodeToDelete);
      nodeToDelete = NULL;
    }
    else
    {
      struct node *ptrToDelete = temp->next;
      temp->next = temp->next->next;
      free(ptrToDelete);
      ptrToDelete = NULL;
    }
  }
}

void deleteAll()
{
  if (headNode == NULL)
    return;
  struct node *temp = headNode;
  do
  {
    free(temp);
    temp = temp->next;
  } while (temp->next != headNode);
  free(headNode);
  temp = NULL;
  headNode = NULL;
}

void update()
{
  int position, age;
  int livePosition = 1;
  printf("Enter Position: ");
  scanf("%d", &position);
  int totalNodes = countLength();

  if (position <= 0 || position > totalNodes)
  {
    printf("Invalid position try again!\n");
    return;
  }

  struct node *temp = headNode;

  while (position > livePosition)
  {
    temp = temp->next;
    livePosition++;
  }

  printf("Enter new Age: ");
  scanf("%d", &age);
  temp->age = age;
}

int main()
{

  int ch;

  while (1)
  {
    printf("\n 1. Add Node First");
    printf("\n 2. Add Node Last");
    printf("\n 3. Insert Node at");
    printf("\n 4. Delete Node at");
    printf("\n 5. update Node at");
    printf("\n 6. Print Nodes");
    printf("\n 7. Count Nodes");
    printf("\n 8. deleteAll Nodes");
    printf("\n 9. Exit\n");
    printf("Enter you option: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      addFirst();
      break;
    case 2:
      addLast();
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
      printElements();
    case 7:
      printf("%d", countLength());
      break;
    case 8:
      deleteAll();
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
