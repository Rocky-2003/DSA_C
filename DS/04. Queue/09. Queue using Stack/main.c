#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100

typedef struct stack
{
  int arr[max];

  int top;
} stack;

// to initalize the stack; and stack is implemented using array;
void initStack(stack *stack) { stack->top = -1; }

// check stack is empty or not
int isEmpty(stack *stack)
{
  if (stack->top == -1)
  {
    return 1;
  }
  return 0;
}

// check stack is full or not
int isFull(stack *stack)
{
  if (stack->top == max - 1)
  {
    return 1;
  }

  return 0;
}

// push elements in stack
void push(stack *stack, int data)
{
  // printf("top s1: %d\n", stack->top);
  stack->top = stack->top + 1;
  stack->arr[stack->top] = data;
  // printf("top s1: %d\n", stack->top);
}

// pop element from stack
int pop(stack *stack)
{
  if (stack->top >= 0)
  {
    return stack->arr[stack->top--];
  }
  return -1; // Stack empty
}

int peek(stack *stack)
{
  if (stack->top >= 0)
  {
    return stack->arr[stack->top];
  }
  return -1; // Stack empty
}

// Here we created a queue struct where we store queue element in stack;
typedef struct queue
{
  stack s1;
  stack s2;

} MyQueue;

// insitalize queue
MyQueue *myQueueCreate()
{

  MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
  initStack(&queue->s1);
  initStack(&queue->s2);
  return queue;
}

// insert element is stack
void myQueuePush(MyQueue *obj)
{
  int data;
  printf("Enter Data: ");
  scanf("%d", &data);
  push(&obj->s1, data);
}

// delte element from queue
int myQueuePop(MyQueue *obj)
{
  if (isEmpty(&obj->s1) && isEmpty(&obj->s2))
  {
    return -1;
  }

  if (isEmpty(&obj->s2))
  {
    while (!isEmpty(&obj->s1))
    {
      int data = pop(&obj->s1);
      push(&obj->s2, data);
    }
  }
  return pop(&obj->s2);
}

int myQueuePeek(MyQueue *obj)
{
  if (isEmpty(&obj->s2))
  {
    while (!isEmpty(&obj->s1))
    {
      int temp = pop(&obj->s1);
      push(&obj->s2, temp);
    }
  }
  printf("Element at Peek is: %d\n", (&obj->s1)->arr[(&obj->s1)->top]);
  return peek(&obj->s1);
}

bool myQueueEmpty(MyQueue *obj)
{

  if (isEmpty(&obj->s1) && isEmpty(&obj->s2))
  {
    printf("Yes, Queue is Empty\n");
    return true;
  }

  printf("No, Queue is Empty\n");
  return false;
}

void display(MyQueue *obj)
{
  if ((&obj->s1)->top == -1 && (&obj->s2)->top == -1)
  {
    printf("Queue is Empty!\n");
    return;
  }
  else if (isEmpty(&obj->s2))
  {
    while (!isEmpty(&obj->s1))
    {
      int data = pop(&obj->s1);
      push(&obj->s2, data);
    }
  }

  for (int i = (&obj->s2)->top; i >= 0; i--)
  {
    printf("Data is: %d\n", (&obj->s2)->arr[i]);
  }

  if (!isEmpty(&obj->s1))
  {
    for (int i = 0; i <= (&obj->s1)->top; i++)
    {
      printf("Data is: %d\n", (&obj->s1)->arr[i]);
    }
  }
}

void myQueueFree(MyQueue *obj)
{

  free(obj);
  obj = NULL;
  printf("Queue is freed!\n");
}

int main()
{
  int ch;

  MyQueue *obj = myQueueCreate();
  while (1)
  {

    printf("1. insert\n");
    printf("2. display\n");
    printf("3. delete\n");
    printf("4. myQueueEmpty\n");
    printf("5. myQueuePeek\n");
    printf("6. freeQueue\n");
    printf("7. Exit\n");

    printf("Choose a option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      myQueuePush(obj);
      break;
    case 2:
      display(obj);
      break;
    case 3:
      myQueuePop(obj);
      break;
    case 4:
      myQueueEmpty(obj);
      break;
    case 5:
      myQueuePeek(obj);
      break;
    case 6:
      myQueueFree(obj);
      break;
    case 7:
      return 0;
      break;
    default:
      printf("Invalid input\n");
      break;
    }
  }
}