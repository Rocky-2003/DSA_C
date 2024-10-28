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
  struct queue *newElement = createElement(data);

  if (front == NULL)
  {
    front = rear = newElement;
    rear->next = front;
  }
  else
  {
    rear->next = newElement;
    rear = newElement;
    rear->next = front;
  }
}

void display()
{
  if (front == NULL)
  {
    printf("Queue is Emtpy\n");
  }
  else
  {
    struct queue *temp = front;
    if (temp->next == front)
    {
      printf("Your data is: %d\n", temp->data);
    }
    else
    {

      do
      {
        printf("Your data is: %d\n", temp->data);
        temp = temp->next;
      } while (temp------ != front);
    }
  }
}

void delete()
{
  if (front == NULL)
  {
    printf("You queue is empty!\n");
  }
  else
  {
    struct queue *temp = front;
    if (temp->next == front)
    {
      front = rear = NULL;
    }
    else
    {
      struct queue *deleteElement = front;
      rear->next = rear->next->next;
      front = front->next;
      free(deleteElement);
      deleteElement = NULL;
    }
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. Insert\n");
    printf("2. display\n");
    printf("3. delete\n");
    printf("4. Exit\n");

    printf("Choose you option: ");
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
      printf("Invalid Option");
      break;
    }
  }
}