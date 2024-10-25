#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char inFix[30] = "x+y^z*p/q^r^s";
// char inFix[30] = "(x-y)/(z+p)*q-r";
char inFix[30] = "a+b/(c*d)*(e+f*g)+h";
char preFix[30];
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
    return 0;
    printf("Stack is empty----------\n");
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
    printf("Stack is Empt=--\n");
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
  {

    return 1;
  }

  return 0;
}

int checkPriority(char ch)
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

void reverseString(char *str)
{
  int i;
  unsigned long l = strlen(str);
  char ch;
  for (i = 0; i < l / 2; i++)
  {
    ch = str[i];
    str[i] = str[l - i - 1];
    str[l - i - 1] = ch;
  }
  // printf("%s", str);
}

void infixToPreFix()
{
  int i, j = 0;
  reverseString(inFix);
  // printf("%s", inFix);
  for (i = 0; inFix[i]; i++)
  {
    printf("for Loop\n");
    if (checkOperand(inFix[i]))
    {
      preFix[j++] = inFix[i];
      printf("Oprand\n");
    }
    else if (inFix[i] == ')')
    {
      push(inFix[i]);
      printf("close bracket\n");
    }
    else if (inFix[i] == '(')
    {
      while (peek() != ')')
      {
        preFix[j++] = pop();
      }
      pop();
      printf("open bracket\n");
    }
    else
    {
      while (top != NULL && checkPriority(inFix[i]) < checkPriority(peek()))
      {
        preFix[j++] = pop();
      }
      push(inFix[i]);
      printf(" opreator\n");
    }
  }

  while (top != NULL)
    preFix[j++] = pop();
  printf(" end\n");
}

int main()
{
  infixToPreFix();
  reverseString(preFix);
  printf("%s", preFix);
  return 0;
}