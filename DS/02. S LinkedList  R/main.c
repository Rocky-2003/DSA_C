#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{

  // int rollNo;
  int age;
  struct Node *next;

  /* data */
};

struct Node *headNode = NULL;

// struct Node *addElement(int rollNo, int age)
struct Node *addElement(int age)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  // newNode->rollNo = rollNo;
  newNode->age = age;
  newNode->next = NULL;
  return newNode;
}

void addFirst()
{
  int ch;
  do
  {
    int rollNo, age;
    struct Node *p1;
    printf("enter age\n");
    scanf("%d", &age);
    // printf("enter rollNo\n");
    // scanf("%d", &rollNo);
    // p1 = addElement(rollNo, age);
    p1 = addElement(age);
    p1->next = headNode;
    headNode = p1;
    printf("Do you want more node(0 for yes, 1 for No!)"); // to clear buffer
    scanf("%d", &ch);
  } while (ch == 0);
}

void addLast()
{
  char ch;
  do
  {

    int rollNo, age;
    struct Node *p1;
    printf("enter age\n");
    scanf("%d", &age);
    // printf("enter rollNo\n");
    // scanf("%d", &rollNo);
    // p1 = addElement(rollNo, age);
    p1 = addElement(age);
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
    fflush(stdin);
    ch = getchar();

  } while (ch == 'y');
}

void printElement()
{
  struct Node *temp = headNode;
  if (temp == NULL)
  {

    printf("Your list is empty!");
  }
  else
  {
    while (temp != NULL)
    {
      // printf("Roll No. : %d, Age: %d\n", temp->rollNo, temp->age);
      printf(" Age: %d\n", temp->age);
      temp = temp->next;
    }
  }
}

int count()
{
  struct Node *temp = headNode;
  int length = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    length++;
  }
  printf("Length is: %d\n", length);
  return length;
}

void insertAt()
{
  struct Node *temp = headNode;
  int position;
  int rollNo, age;
  int lastPosition = count(temp) + 1;
  struct Node *trav1;
  struct Node *trav2;

  // Created a new Node;
  struct Node *newNode;
  printf("enter position: \n");
  scanf("%d", &position);
  printf("enter age\n");
  scanf("%d", &age);
  // printf("enter rollNo\n");
  // scanf("%d", &rollNo);
  // newNode = addElement(rollNo, age);
  newNode = addElement(age);

  if (position <= lastPosition && position > 0)
  {
    int livePosition = 1;
    if (position == 1)
    {
      newNode->next = headNode;
      headNode = newNode;
    }
    else
    {

      while (temp != NULL)
      {

        if (livePosition == position - 1)
        {
          trav1 = temp;
        }
        else if (livePosition == position)
        {
          trav2 = temp;
        }
        temp = temp->next;
        livePosition++;
      }
      trav1->next = newNode;
      newNode->next = trav2;
    }
  }
  else
  {
    printf("Invalid Position");
  }
}

void deleteNodeByAge()
{
  int age;
  printf("Enter the Age to Delete  Node: ");
  scanf("%d", &age);

  if(age==0)
    return;
  if (headNode->age == age)
  {

    if (headNode->next == NULL)
    {
      free(headNode);
      headNode = NULL;
    }
    else
    {
      struct Node *temp = headNode;
      headNode = headNode->next;
      free(temp);
      temp = NULL;
    }
  }
  else
  {
    struct Node *temp = headNode;
    struct Node *beforeTemp = NULL;
    while (temp != NULL && temp->age == age)
    {
      beforeTemp = temp;
      temp = temp->next;
    }

    if (temp != NULL)
    {
      beforeTemp->next = temp->next;
      free(temp);
      temp == NULL;
    }
    else
    {
      printf("Enter a valid age\n");
      deleteNodeByAge();
    }
  }
}

void findMid()
{
  if (headNode == NULL)
  {
    printf("List is empty!");
  }
  else if (headNode->next == NULL)
  {
    printf("There is only one Node in the List");
  }
  else
  {
    struct Node *temp1 = headNode;
    struct Node *temp2 = headNode;

    while (temp1 != NULL)
    {
      temp1 = temp1->next;
      if (temp1->next != NULL)
        temp1 = temp1->next;
      if (temp1->next != NULL)
        temp2 = temp2->next;
    }

    printf("Middle Node, Data's Age is: %d", temp2->age);
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("\n 1. Add Node First");
    printf("\n 2. Add Node Last");
    printf("\n 3. Print Nodes");
    printf("\n 4. Count Nodes");
    printf("\n 5. Insert Node at");
    printf("\n 6. Delete by age Node at");
    printf("\n 7. Find Middle Node");
    // printf("\n 8. reverseList");
    printf("\n 8. Exit\n");

    printf("Enter the Option Number:\n");
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
      printElement();
      break;
    case 4:
      count();
      break;
    case 5:
      insertAt();
      break;
    case 6:
      deleteNodeByAge();
      break;
    case 7:
      findMid();
      break;
    case 8:
      return 0;
      break;
    default:
      printf("Enter any Option");
      break;
    }
  }

  return 0;
}