#include <stdio.h>
#include <stdlib.h>

struct node
{
  int age;
  struct node *next;
};

struct node *list1 = NULL;
struct node *list2 = NULL;

struct node *addElement(int age)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->age = age;
  newNode->next = NULL;

  // headNode->next->next->next = headNode->next;
  return newNode;
}

void getInput(int *age)
{
  printf("Enter your age: ");
  scanf("%d", age);
}

void addFirst(struct node **headNode)
{
  int res = 1;
  do
  {
    int age;
    getInput(&age);
    struct node *n = addElement(age);
    if (*headNode == NULL)
    {
      n->next = *headNode;
      *headNode = n;
    }
    else
    {
      struct node *temp = *headNode;
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

void printElements(struct node *headNode)
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

struct node *mergeTwoLists(struct node *list1, struct node *list2)
{
  struct node *temp1 = list1;
  struct node *temp2 = list2;
  struct node *start, *last;

  if (temp1->age < temp2->age)
  {
    start = last = temp1;
    temp1 = temp1->next;
    last->next = NULL;
  }
  else
  {
    start = last = temp2;
    temp2 = temp2->next;
    last->next = NULL;
  }

  while (temp1 && temp2)
  {
    if (temp1->age < temp2->age)
    {
      last->next = temp1;
      last = temp1;
      temp1 = temp1->next;
      last->next = NULL;
    }
    else
    {
      last->next = temp2;
      last = temp2;
      temp2 = temp2->next;
      last->next = NULL;
    }
  }

  if (temp1)
  {
    last->next = temp1;
  }
  else if (temp2)
  {
    last->next = temp2;
  }
  printElements(start);
  return start;
}

int main()
{

  int ch, listChoice;

  while (1)
  {
    printf("\nChoose Linked List to operate on (1 or 2): ");
    scanf("%d", &listChoice);

    struct node **selectedList = (listChoice == 1) ? &list1 : &list2;

    printf("\n 1. Add Node First");
    printf("\n 2. printElements");
    printf("\n 3. mergeSort");
    printf("\n 4. Exit\n");
    printf("Enter you option: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      addFirst(selectedList);
      break;
    case 2:
      printElements(*selectedList);
      break;
    case 3:
      mergeTwoLists(list1, list2);
      break;

    case 4:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }

  return 0;
}
