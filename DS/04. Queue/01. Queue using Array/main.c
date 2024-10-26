#include <stdio.h>

#define size 5

int queue[size];

int front = -1;
int rear = -1;

void insert()
{
  int data;
  if (rear == size - 1)
  {
    printf("Queue is Full!\n");
    return;
  }

  printf("Enter the data: ");
  scanf("%d", &data);

  queue[++rear] = data;
  if (rear >= 0)
  {
    front = 0;
  }
}

void display()
{
  if (rear == -1)
  {
    printf("Queue is empty!\n");
    return;
  }

  for (int i = front; i <= rear; i++)
  {
    printf("You data is: %d\n", queue[i]);
  }
}

void delete()
{
  if (rear == -1)
  {
    printf("Queue is Empt!\n");
    return;
  }

  for (int i = front; i < rear; i++)
  {
    queue[i] = queue[i + 1];
  }
  rear = rear - 1;
  if (rear == -1)
  {
    front == -1;
  }
}

int main()
{
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