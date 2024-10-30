#include <stdio.h>
#define size 10

struct Array
{
  int data;
  int priority;
};

struct Array queue[size];
int front = -1;
int rear = -1;
void insert()
{
  if (rear == size - 1)
  {
    printf("Queue is Full!\n");
    return;
  }

  int data, priority, i;
  printf("Enter data: \n");
  scanf("%d", &data);
  printf("Enter Priority: \n");
  scanf("%d", &priority);

  if (front == -1)
  {
    i = -1;
    front = rear = 0;
    printf("called1\n");
  }
  else
    // for (i = rear; i >= 0 && queue[i].priority > priority; i--)
    for (i = rear-1; i >= 0 && queue[i].priority < priority; i--)
    {

      printf("called2\n");
      queue[i + 1] = queue[i];
    }

  queue[i + 1].data = data;
  queue[i + 1].priority = priority;
  rear++;
  printf("called3\n");
}

void display()
{
  if (front == -1)
  {
    printf("Queue is Empty!\n");
  }
  else
  {
    // for (int i = front; i < rear; i++)
    for (int i = rear-1; i >=front; i--)
    {

      // printf("I is: %d\n", i);
      printf("Data is: %d, Priority is: %d\n", queue[i].data, queue[i].priority);
    }
  }
}

void delete()
{
  if (front == -1)
  {
    printf("Queue is Empty!\n");
  }
  else
  {
    // for (int i = front; i < rear; i++){
      //   queue[i] = queue[i + 1];
      // }
      rear--;
    if (rear == -1)
      front = -1;
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
      printf("Ivalid option\n");
      break;
    }
  }
}