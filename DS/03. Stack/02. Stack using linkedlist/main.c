#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int data;
  struct stack *next;
};

struct stack *top = NULL;

struct stack *newElement(int data)
{
  struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
  ptr->data = data;
  ptr->next = NULL;
  return ptr;
}

int getInput()
{
  int data;
  printf("enter the data: ");
  scanf("%d", &data);
  return data;
}

void push()
{
  int ch;
  do
  {

    int data = getInput();
    struct stack *newNode = newElement(data);
    if (top == NULL)
    {
      top = newNode;
    }
    else
    {
      newNode->next = top;
      top = newNode;
    }
    printf("If you want to push more enter 0, otherwise 1: ");
    scanf("%d", &ch);
  } while (ch == 0);
}

void pop()
{
  int ch;
  do
  {
    if (top == NULL)
    {
      printf("Stack is empty\n");
    }
    else if (top->next == NULL)
    {
      free(top);
      top = NULL;
    }
    else
    {
      struct stack *temp = top;
      top = top->next;
      free(temp);
      temp = NULL;
    }
    printf("Enter 0 to continue pop element, otherwise 1: ");
    scanf("%d", &ch);
  } while (ch == 0);
}

void display()
{
  if (top == NULL)
  {
    printf("Stack is Empty\n");
  }
  else
  {
    struct stack *temp = top;
    while (temp != NULL)
    {
      printf("Data is: %d\n", temp->data);
      temp = temp->next;
    }
  }
}

void peek()
{
  if (top == NULL)
  {
    printf("Stack is Empty!\n");
  }
  else
  {

    printf("Data is: %d\n", top->data);
  }
}

int main()
{

  int ch;
  while (1)
  {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    printf("\n");
    printf("Choose you option: ");
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
      printf("Invalid Input");
      break;
    }
  }
}