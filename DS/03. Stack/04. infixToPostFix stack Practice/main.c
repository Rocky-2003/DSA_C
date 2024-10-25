#include <stdio.h>
#include <stdlib.h>

// char infix[30] = "a+b/(c*d)*(e+f*g)+h";
// char infix[30] = "(x-y)/(z+p)*q-r";
char infix[30] = "x+y^z*p/q^r^s";
char postFix[30];

struct stack
{
  char data;
  struct stack *next;
};

struct stack *top = NULL;

struct stack *newElement(char data)
{
  struct stack *newEl = (struct stack *)malloc(sizeof(struct stack));
  newEl->data = data;
  newEl->next = NULL;
  return newEl;
}

void push(char data)
{
  struct stack *element = newElement(data);
  if (top == NULL)
    top = element;
  else
    element->next = top;
  top = element;
}

char pop()
{
  char data;

  if (top == NULL)
    printf("Stack is empty\n");
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

char peek()
{
  // if (top == NULL)
  //   return 0;
  // else
  //   return top->data;
  return top ? top->data : '\0';
}

int checkAlpha(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z') || (ch >= '0' && ch <= '9'))
  {
    return 1;
  }
  return 0;
}

int checkOperator(char ch)
{
  if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else
  {
    return -1;
  }
}

void infixToPostFix()
{
  int i, j = 0;
  for (i = 0; infix[i]; i++)
  {
    if (checkAlpha(infix[i]))
    {
      postFix[j++] = infix[i];
    }
    else if (infix[i] == '(')
    {
      push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (peek() != '(')
      {
        postFix[j++] = pop();
      }
      pop();
    }
    else
    {
      while (top != NULL && checkOperator(infix[i]) <= checkOperator(peek()))
      {
        postFix[j++] = pop();
      }
      push(infix[i]);
    }
  }
  while (top != NULL)
  {
    postFix[j++] = pop();
  }
}

int main()
{

  int i;
  infixToPostFix();
  for (i = 0; postFix[i]; i++)
    printf("%c ", postFix[i]);

  return 0;
}