#include <stdio.h>

#define size 5

int queue[size];

int front = -1;
int rear = -1;

void insert()
{

  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("Queue is Full!\n");
    return;
  }
  if (front == -1)
  {
    front = rear = 0;
  }
  else if (rear == size - 1)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }
  printf("Enter the data: ");
  scanf("%d", &queue[rear]);
}

void display()
{
  if (rear == -1)
  {
    printf("Queue is empty!\n");
    return;
  }
  else if (rear > front)
  {
    for (int i = front; i <= rear; i++)
    {
      printf("Your data is: %d\n", queue[i]);
    }
  }
  else if (front > rear)
  {
    for (int i = front; i < size; i++)
    {
      printf("Your data is: %d\n", queue[i]);
    }
    for (int i = 0; i <= rear; i++)
    {
      printf("Your data is: %d\n", queue[i]);
    }
  }
  else if (front == rear && front != -1)
  {
    printf("Your data is: %d\n", queue[front]);
  }
}

void delete()
{
  if (rear == -1)
  {
    printf("Queue is Empt!\n");
    return;
  }
  else if (front == rear)
  {
    front = rear = -1;
  }
  else if (front > size - 1)
  {
    front = 0;
  }
  else
  {
    front++;
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