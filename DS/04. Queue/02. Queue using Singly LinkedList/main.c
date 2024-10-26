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

int getInput()
{
  int data;
  printf("Enter the data: ");
  scanf("%d", &data);
  return data;
}

void insert()
{
  int data = getInput();
  struct queue *newElement = createElement(data);
  if (rear == NULL && front == NULL)
  {
    front = rear = newElement;
  }
  else
  {
    rear->next = newElement;
    rear = newElement;
  }
}

void display()
{

  if (rear == NULL)
  {
    printf("Your Queue is Empty!\n");
    return;
  }
  struct queue *temp = front;
  while (temp != NULL)
  {
    printf("Your data is: %d\n", temp->data);
    temp = temp->next;
  }
}

void delete()
{
  if (rear == NULL)
  {
    printf("Your Queue is Empty!\n");
    return;
  }

  struct queue *elementToDelete = front;
  front = front->next;
  if (front == NULL)
  {
    rear = NULL;
  }
  free(elementToDelete);
  elementToDelete = NULL;
}


int main(){
  int ch;
  while (1)
  {
    printf("1. insert element\n");
    printf("2. display element\n");
    printf("3. delete element\n");
    printf("4. exit element\n");

    printf("Enter your option: ");
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
      printf("Invalid option\n");
      break;
    }
  }
}