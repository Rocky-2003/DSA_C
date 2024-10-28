#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int data;
  struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

struct queue *createElement(int data)
{
  struct queue *newElement = (struct queue *)malloc(sizeof(struct queue));
  newElement->data = data;
  newElement->next = NULL;
  return newElement;
}

void insert()
{
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  struct queue *newElm = createElement(data);

  if (front == NULL)
  {

    printf("First\n");
    front = rear = newElm;
  }
  else
  {
    struct queue *beforeTemp = NULL;
    struct queue *temp = front;

    while (temp != NULL && newElm->data > temp->data)
    {
      printf("Loop\n");
      beforeTemp = temp;
      temp = temp->next;
    }
    if (beforeTemp && temp)
    {
      printf("B&T\n");
      newElm->next = temp;
      beforeTemp->next = newElm;
    }
    else if (temp == NULL)
    {
      printf("B\n");
      beforeTemp->next = newElm;
    }
    else if (beforeTemp == NULL)
    {
      printf("head\n");
      newElm->next = temp;
      front = newElm;
    }
  }
}

void display()
{
  if (front == NULL)
  {
    printf("Queue is Empty!\n");
  }
  else
  {
    struct queue *temp = front;
    while (temp != NULL)
    {
      printf("Your data is: %d\n", temp->data);
      temp = temp->next;
    }
  }
}

void delete()
{
  if (front == NULL)
    printf("Queue is Empty!\n");
  else
  {
    struct queue *temp = front;
    front = front->next;
    free(temp);
    temp = NULL;
    if (front == NULL)
      rear = NULL;
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. insert\n");
    printf("2. display\n");
    printf("3. delete\n");
    printf("4. Exit\n");

    printf("Choose your option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert();
      break;
    case 2:
      display();
      break;
    case 3:
      delete ();
      break;
    case 4:
      return 0;
      break;

    default:
      printf("Ivalid option");
      break;
    }
  }
}
