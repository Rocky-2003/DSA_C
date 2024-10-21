#include <stdio.h>
#include <stdlib.h>

struct stack
{
  char data;
  struct stack *next;
};

struct stack *top = NULL;

struct stack *addElement(char data)
{
  struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
  ptr->data = data;
  ptr->next = NULL;
}

void push(char data)
{
  struct stack *newElement = addElement(data);
  if (top == NULL)
  {
    top = newElement;
  }
  else
  {
    newElement->next = top;
    top = newElement;
  }
}

void pop()
{
  if (top == NULL)
  {
    printf("List is Empty!");
    return;
  }

  struct stack *elementToDelete = top;
  top = top->next;
  free(elementToDelete);
  elementToDelete = NULL;
}

void display()
{
  if (top == NULL)
  {
    printf("stack is Empty!");
    return;
  }

  struct stack *temp = top;
  while (temp != NULL)
  {
    printf("Data is: %d", temp->data);
    temp = temp->next;
  }
}

void peek()
{
  if (top == NULL)
  {
    printf("stack is Empty!");
  }
  else
  {
    printf("Data at peek is: %d", top->data);
  }
}

int isbalanced(char *str)
{

  for (int i = 0; str[i]; i++)
  {
    if (str[i] == '[' || str[i] == '(' || str[i] == '{')
    {
      push(str[i]);
    }
    else if (str[i] == ']')
    {
      if (top == NULL || top->data != '[')
        return 0;
      pop();
    }
    else if (str[i] == ')')
    {
      if (top == NULL || top->data != '(')
        return 0;
      pop();
    }
    else if (str[i] == '}')
    {
      if (top == NULL || top->data != '{')
      {
        return 0;
      }
      pop();
    }
  }

  if (top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{

  int x;
  char str[20] = "[[({})]]}";
  x = isbalanced(str);

  if (x == 1)
  {
    printf("Bracket are balanced!\n");
  }
  else
  {

    printf("Bracket are not balanced!\n");
  }
  return 0;
}
