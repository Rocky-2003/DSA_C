#include <stdio.h>
#include <stdlib.h>

char ch[30] = "100 20 - 15 5 + /";

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

int pop()
{

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
    int data = top->data;
    top = top->next;
    free(temp);
    return data;
  }
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
  }
}

void findPostFix()
{
  int i, j = 0;
  char num[30];
  for (i = 0; ch[i]; i++)
  {
    if (ch[i] >= '0' && ch[i] <= '9')
    {
      num[j++] = ch[i];
    }
    else if (ch[i] == '+')
    {
      int x, y, sum;
      x = pop();
      y = pop();
      sum = x + y;
      push(atoi(sum));
    }
    else if (ch[i] == '-')
    {
      int x, y, sum;
      x = pop();
      y = pop();
      sum = y - x;
      push(atoi(sum));
    } else if(ch[i]=='*'){
      int x, y, sum;
      x = pop();
      y = pop();
      sum = y - x;
      push(atoi(sum));
    }
  }
}

int main()
{
}