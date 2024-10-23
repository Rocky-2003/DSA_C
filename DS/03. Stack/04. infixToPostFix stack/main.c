#include <stdio.h>
#include <stdlib.h>

char inFix[30] = "(x-y)/(z+p)*q-r";
// char inFix[30] = "a+b/(c*d)*(e+f*g)+h";
char postFix[30];
struct stack
{
  char data;
  struct stack *next;
};

struct stack *top = NULL;

struct stack *newElement(char data)
{
  struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
  ptr->data = data;
  ptr->next = NULL;
  return ptr;
}

void push(char data)
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

char pop()
{
  char data;
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
    // temp = NULL;
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

char peek()
{

  // printf("Data is: %d\n", top->data);
  return top ? top->data : '\0';
}

int checkOperand(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    return 1;
  return 0;
}

int checkPriority(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else
    return -1;
}

void inFixToPostFix()
{
  int i, j = 0;
  for (i = 0; inFix[i]; i++)
  {
    if (checkOperand(inFix[i]))
    {
      postFix[j++] = inFix[i];
    }
    else if (inFix[i] == '(')
    {
      push(inFix[i]);
    }
    else if (inFix[i] == ')')
    {
      while (peek() != '(')
        postFix[j++] = pop();
      pop();
    }
    else
    {
      while (top != NULL && checkPriority(inFix[i]) <= checkPriority(peek()))
        postFix[j++] = pop();
      push(inFix[i]);
    }
  }

  while (top != NULL)
    postFix[j++] = pop();
  // postFix[j] = '\0';
}

int main()
{
  int i;
  inFixToPostFix();
  for (i = 0; postFix[i]; i++)
    printf("%c ", postFix[i]);

  return 0;
}