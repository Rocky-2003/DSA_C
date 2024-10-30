#include <stdio.h>
#include <Stdlib.h>

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
}

void insert()
{
  int data;
  printf("Enter the Data: ");
  scanf("%d", &data);
  struct dequeue *newElement = createElement(data);

  if (front == NULL)
  {
    front = rear = newElement;
  }
  else
  {
    newElement->prev = rear;
    rear->next = newElement;
    rear = newElement;
  }
}

void displayLeft()
{
  if (front == NULL)
  {
    printf("Dequeue is Empty`\n");
  }
  else
  {
    struct dequeue *temp = front;
    while (temp != NULL)
    {
      printf("Data is : %d\n", temp->data);
      temp = temp->next;
    }
  }
}
void displayRight()
{
  if (front == NULL)
  {
    printf("Dequeue is Empty`\n");
  }
  else
  {
    struct dequeue *temp = rear;
    while (temp != NULL)
    {
      printf("Data is : %d\n", temp->data);
      temp = temp->prev;
    }
  }
}

void deleteLeft()
{
  if (front == NULL)
  {
    printf("Dequeu is Empty!\n");
  }
  else
  {
    struct dequeue *temp = front;
    front = front->next;
    front->prev = NULL;
    free(temp);
    temp == NULL;
    if (front == NULL || rear == NULL)
      front = rear = NULL;
  }
}

void deleteRight()
{
  if (front == NULL)
  {
    printf("Dequeu is Empty!\n");
  }
  else
  {
    struct dequeue *temp = rear;
    rear = rear->prev;
    rear->next = NULL;
    free(temp);
    temp == NULL;
    if (front == NULL || rear == NULL)
      front = rear = NULL;
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. insert\n");
    printf("2. displayLeft\n");
    printf("3. displayRight\n");
    printf("4. deleteLeft\n");
    printf("5. deleteRight\n");
    printf("6. Exit\n");

    printf("Choose your option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert();
      break;
    case 2:
      displayLeft();
      break;
    case 3:
      displayRight();
      break;
    case 4:
      deleteLeft();
      break;
    case 5:
      deleteRight();
      break;
    case 6:
      return 0;
      break;

    default:
      printf("Ivalid option\n");
      break;
    }
  }
}