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
    struct node *n = addElement(age);
    n->next = headNode;
    headNode = n;
    printf("Do you want to add more nodes 0 for yes & 1 for no:");
    scanf("%d", &res);
  } while (res == 0);
}

void addLast()
{
  int res = 1;
  do
  {
    int age;
    getInput(&age);
    struct node *n = addElement(age);
    if (headNode == NULL)
    {
      n->next = headNode;
      headNode = n;
    }
    else
    {
      struct node *temp = headNode;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = n;
    }
    printf("Do you want to add more nodes 0 for yes & 1 for no:");
    scanf("%d", &res);
  } while (res == 0);
}

void printElements()
{

  if (headNode == NULL)
  {
    printf("LinkedList is Empty!");
    return;
  }

  struct node *temp = headNode;
  while (temp != NULL)
  {
    printf("Age is: %d\n", temp->age);
    temp = temp->next;
  }
}

int countLength()
{
  struct node *temp = headNode;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }

  printf("Total no. of count is: %d\n", count);
  return count;
}

void insertAt()
{
  int age, i, position;
  int leng = countLength();
  printf("Enter position where to insert: ");
  scanf("%d", &position);

  if (position < 1 || position >= leng + 1)
  {
    printf("Invalid position!");
    return;
  }

  getInput(&age);
  struct node *n = addElement(age);
  if (position == 1)
  {
    n->next = headNode;
    headNode = n;
    return;
  }

  struct node *temp = headNode;
  for (i = 1; i < position - 1; i++)
  {
    temp = temp->next;
  }

  n->next = temp->next;
  temp->next = n;
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
    struct node *temp = headNode->next;
    headNode = headNode->next;
    free(temp);
    temp = NULL;
    return;
  }
  else
  {
    int livePosition = 1;
    struct node *temp = headNode;
    while (position - 1 > livePosition)
    {
      temp = temp->next;
      livePosition++;
    }

    struct node *ptrToDelete = temp->next;
    temp->next = temp->next->next;
    free(ptrToDelete);
    ptrToDelete = NULL;
    return;
  }
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

void reverseList()
{

  struct node *currentNode = headNode;
  struct node *nextNode;
  struct node *lastNode;

  do
  {

    nextNode = currentNode->next;
    currentNode->next = lastNode;
    lastNode = currentNode;
    currentNode = nextNode;
  } while (currentNode != NULL);
  headNode = lastNode;
};

// void deleteNodeByAge()
// {
//   if (headNode == NULL)
//   {
//     printf("List is Empty!");
//     return;
//   }
//   int age;
//   printf("Enter age to delete Node:");
//   scanf("%d", &age);
//   if (age == 0)
//   {
//     printf("Enter a valid Age");
//     return;
//   }
//   struct node *temp = headNode;
//   struct node *beforeTemp;
//   while (temp != NULL || temp->age == age)
//   {
//     beforeTemp = temp;
//     temp = temp->next;
//   }
//   if (headNode->next == NULL && headNode->age == age)
//   {
//     free(headNode);
//     free(beforeTemp);
//     free(temp);
//     beforeTemp = temp = headNode = NULL;
//   }
//   else if (headNode->next != NULL && headNode->age == age)
//   {
//     headNode = temp;
//     free(beforeTemp);
//     free(temp);
//     beforeTemp = temp = NULL;
//   }
//   else
//   {
//     beforeTemp->next = temp->next;
//     free(temp);
//     temp = NULL;
//   }
// }

void deleteNodeByAge()
{
  if (headNode == NULL)
  {
    printf("List is Empty!\n");
    return;
  }

  int age;
  printf("Enter age to delete Node: ");
  scanf("%d", &age);

  if (age <= 0)
  {
    printf("Enter a valid Age\n");
    return;
  }

  struct node *temp = headNode;
  struct node *beforeTemp = NULL;

  // If the head node itself holds the age to be deleted
  if (headNode->age == age)
  {
    temp = headNode;           // Store the current head
    headNode = headNode->next; // Move head to the next node
    free(temp);                // Free the old head
    printf("Node with age %d deleted (Head Node).\n", age);
    return;
  }

  // Traverse the list to find the node to delete
  while (temp != NULL && temp->age != age)
  {
    beforeTemp = temp; // Track the node before the one to delete
    temp = temp->next;
  }

  // If the node with the given age is not found
  if (temp == NULL)
  {
    printf("Node with age %d not found.\n", age);
    return;
  }

  // Node found; unlink it from the list
  beforeTemp->next = temp->next;
  free(temp); // Free the memory of the node to delete
  printf("Node with age %d deleted.\n", age);
}

void addToSorted()
{
  if (headNode == NULL)
  {
    printf("List is Empty!");
    return;
  }
  int age;
  printf("Enter the age of new node:");
  scanf("%d", &age);
  struct node *newNode = addElement(age);

  struct node *temp = headNode;
  struct node *beforeTemp;
  while (temp != NULL && temp->age < newNode->age)
  {
    beforeTemp = temp;
    temp = temp->next;
  }

  if (temp == headNode)
  {
    newNode->next = headNode;
    headNode = newNode;
  }
  else
  {
    newNode->next = temp;
    beforeTemp->next = newNode;
  }
}

int checkSorted()
{

  if (headNode == NULL || headNode->next == NULL)
  {

    return 1;
  }

  struct node *temp = headNode;
  while (temp != NULL)
  {
    if (temp->age > temp->next->age)
    {
      return 0;
    }
    temp = temp->next;
  }
  return 1;
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
    printf("\n 8. reverseList");
    printf("\n 9. DeleteNodeByAge");
    printf("\n 10. addToSorted");
    printf("\n 11. checkSorted");
    printf("\n 12. Exit\n");
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
      reverseList();
      break;
    case 9:
      deleteNodeByAge();
      break;
    case 10:
      addToSorted();
      break;
    case 11:
      checkSorted();
      break;
    case 12:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }

  return 0;
}
