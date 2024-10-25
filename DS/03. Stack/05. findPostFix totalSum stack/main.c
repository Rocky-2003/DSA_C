#include <stdio.h>
#include <stdlib.h>
char postFix[30] = "100 20 - 15 5 + /";
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

void push(int data)
{

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
}

int pop()
{

  int data;
  if (top == NULL)
  {
    printf("Stack is empty\n");
  }
  // else if (top->next == NULL)
  // {
  //   free(top);
  //   top = NULL;
  // }
  else
  {
    struct stack *temp = top;
    data = top->data;
    top = top->next;
    free(temp);
    temp = NULL;
  }
  return data;
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

int peek()
{
  if (top == NULL)
  {
    printf("Stack is Empty!\n");
  }
  else
  {
    return top->data;
    // printf("Data is: %d\n", top->data);
  }
}
int checkOperand(char ch)
{
  if (ch >= '0' && ch <= '9')
  {
    return 1;
  }
  return 0;
}

void calculatePostFix()
{
  int i;
  for (i = 0; postFix[i]; i++)
  {
    if (checkOperand(postFix[i]))
    {
      int n = 0;
      while (postFix[i] != ' ')
      {
        n = n * 10 + (postFix[i] - '0');
        i++;
      }
      push(n);
    }
    else if (postFix[i] == ' ')
    {
      continue;
    }
    else
    {
      int x, y, z;
      if (postFix[i] == '-')
      {
        x = pop();
        y = pop();
        z = y - x;
        push(z);
      }
      else if (postFix[i] == '+')
      {
        x = pop();
        y = pop();
        z = y + x;
        push(z);
      }
      else if (postFix[i] == '*')
      {
        x = pop();
        y = pop();
        z = y * x;
        push(z);
      }
      else if (postFix[i] == '/')
      {
        x = pop();
        y = pop();
        z = y / x;
        push(z);
      }
    }
  }
}

int main()
{
  calculatePostFix();
  int sum = peek();
  printf("%d", sum);
}