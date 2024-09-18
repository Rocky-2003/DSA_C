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
  char ch;
  do
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
    printf("Do you want more node(y,n)");
    fflush(stdin); // to clear buffer
    ch = getchar();
  } while (ch == 'y');
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
    fflush(stdin);
    ch = getchar();

  } while (ch == 'y');
}

void printElement(struct Node *temp)
{

  if (temp == NULL)
  {

    printf("Your list is empty!");
  }
  else
  {
    while (temp != NULL)
    {
      printf("Roll No. : %d, Age: %d\n", temp->rollNo, temp->age);
      temp = temp->next;
    }
  }
}
int count(struct Node *temp)
{
  int length = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    length++;
  }
  printf("Length is: %d\n", length);
  return length;
}
void insertAt(struct Node *temp)
{

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
  printf("enter rollNo\n");
  scanf("%d", &rollNo);
  newNode = addElement(rollNo, age);

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

int main()
{
  addFirst();

  printElement(headNode);

  insertAt(headNode);
  printElement(headNode);

  return 0;
}