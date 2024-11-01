#include <stdio.h>
#include <stdlib.h>

struct dequeue
{
  int data;

  struct dequeue *next;
  struct dequeue *prev;
};

struct dequeue *front = NULL;
struct dequeue *rear = NULL;

struct dequeue *createElement(int data)
{
  struct dequeue *newElm = (struct dequeue *)malloc(sizeof(struct dequeue));
  newElm->data = data;
  newElm->next = NULL;
  newElm->prev = NULL;
  return newElm;
}

void insertRight()
{
  int data;
  printf("Enter Data: ");
  scanf("%d", &data);

  struct dequeue *newElement = createElement(data);

  if (front == NULL)
  {
    rear = front = newElement;
  }
  else
  {
    rear->next = newElement;
    newElement->prev = rear;
    rear = newElement;
  }
}
void insertLeft()
{
  int data;
  printf("Enter Data: ");
  scanf("%d", &data);

  struct dequeue *newElement = createElement(data);

  if (front == NULL)
  {
    rear = front = newElement;
  }
  else
  {
    front->prev = newElement;
    newElement->next = front;
    front = newElement;
  }
}

void display()
{
  if (front == NULL)
    printf("Your Dequeue is Empty!\n");
  else
  {
    struct dequeue *temp = front;
    while (temp != NULL)
    {
      printf("Data is: %d\n", temp->data);
      temp = temp->next;
    }
  }
}

void delete()
{

  printf("%d\n", front->data);
  struct dequeue *temp = front;
  if (front == NULL)
  {

    printf("Dequeue is Empty!\n");
  }
  else if (front->next == NULL)
  {
    front = rear = NULL;
  }
  else
  {
    front = front->next;
    if (front)
      front->prev = NULL;
  }
  free(temp);
  temp = NULL;
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. insertLeft\n");
    printf("2. insertRight\n");
    printf("3. display\n");
    printf("4. delete\n");
    printf("5. Exit\n");

    printf("Choose your option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

      insertLeft();
      break;
    case 2:
      insertRight();
      break;
    case 3:
      display();
      break;
    case 4:
      delete ();
      break;
    case 5:
      return 0;
      break;

    default:
      printf("Ivalid option\n");
      break;
    }
  }
}