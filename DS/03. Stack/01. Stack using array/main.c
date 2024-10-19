#include <stdio.h>
#define size 5

int stack[size];
int top = -1;

void push()
{
  int ch;
  do
  {

    if (top == size-1)
    {
      printf("Stack is full!\n");
      return;
    }

    int data;
    printf("Enter the data: ");
    scanf("%d", &stack[++top]);

    printf("Do you want to push more element enter 0, ohterWise 1:");
    scanf("%d", &ch);
  } while (ch == 0);
}

void pop()
{
  int ch;
  do
  {

    if (top == -1)
    {
      printf("Stack is Empty\n");
      return;
    }

    top--;
    printf("Do you want to pop more element enter 0, ohterWise 1:");
    scanf("%d", &ch);
  } while (ch == 0);
}

void display()
{
  if (top == -1)
  {
    printf("Stack is Empty\n");
    return;
  }

  for (int i = top; i >= 0; i--)
  {
    printf("Data is : %d\n", stack[i]);
  }
}

void peek()
{
  if (top == -1)
  {
    printf("Stack is Empty\n");
    return;
  }

  printf("Data at peek is: %d\n", stack[top]);
}

int main()
{

  int ch;
  while (1)
  {
    printf("1. Push element\n");
    printf("2. pop element\n");
    printf("3. display element\n");
    printf("4. peek element\n");
    printf("5. Exit\n");
    printf("Choose any option:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      peek();
      break;
    case 5:
      return 0;
      break;

    default:
      printf("Invalid Option\n");
      break;
    }
  }

  return 0;
}