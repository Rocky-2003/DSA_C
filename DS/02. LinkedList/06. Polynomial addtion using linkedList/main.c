#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char data;
  int coeff;
  struct node *next;
};

struct node *head = NULL;
char str1[] = "2x^2+2x+3";
char str2[] = "2x^2+2x+3";

struct node *createNode(char data, int coeff)
{
  struct node *newEl = (struct node *)malloc(sizeof(struct node));
  newEl->data = data;
  newEl->coeff = coeff;
  newEl->next = NULL;
  return newEl;
}

void addNode(char data, int coeff)
{

  struct node *newNode = createNode(data, coeff);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    struct node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void display()
{
  if (head == NULL)
    printf("List is Empty!\n");
  else
  {
    struct node *temp = head;
    while (temp != NULL)
    {
      printf("Data is: %c\n", temp->data);
      temp = temp->next;
    }
  }
}

void addPollyNomial1(char str[])
{
  int n = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    char ch = str[i];
    if (ch >= 0 && ch <= 9)
    {
      while (ch >= 0 && ch <= 9)
      {
        n = 10 * n + (ch - '0');
      }
    }
    else
    {
      addNode(ch, n);
    }
  }
}

int main()
{

  addPollyNomial1(str1);

  display();
}