#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  int age;
  struct Node *prev;
  struct Node *next;
};

struct Node *list1 = NULL;
struct Node *list2 = NULL;
struct Node *createNode(int age)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->age = age;
  ptr->prev = NULL;
  ptr->next = NULL;
  return ptr;
}

void addFirst(struct Node **headNode)
{
  int ch = 1;
  do
  {
    int age;
    printf("Enter age:");
    scanf("%d", &age);
    struct Node *newNode = createNode(age);
    if (*headNode == NULL)
    {
      // newNode->next = headNode;
      *headNode = newNode;
    }
    else
    {
      (*headNode)->prev = newNode;
      newNode->next = *headNode;
      *headNode = newNode;
    }

    printf("Enter 0 for continue to add or 1 to stop: ");
    scanf("%d", &ch);
  } while (ch == 0);
}

void addLast(struct Node **headNode)
{
  int ch = 1;
  do
  {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);
    struct Node *newNode = createNode(age);
    if (*headNode == NULL)
    {

      *headNode = newNode;
    }
    else
    {
      struct Node *temp = *headNode;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }

      temp->next = newNode;
      newNode->prev = temp;
    }
    printf("Enter 0 for continue to add or 1 to stop: ");
    scanf("%d", &ch);

  } while (ch == 0);
}

int countNodes(struct Node *headNode)
{
  struct Node *temp = headNode;
  int totalNodes = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    totalNodes++;
  }
  return totalNodes;
}

void printList(struct Node *headNode)
{
  if (headNode == NULL)
  {
    printf("List is Empty");
    return;
  }
  else
  {
    struct Node *temp = headNode;
    while (temp != NULL)
    {

      printf("Age is: %d, prev: %d, next: %d\n", temp->age, temp->prev, temp->next);
      temp = temp->next;
    }
  }
}

void printReverse(struct Node *headNode)
{
  if (headNode == NULL)
    return;
  struct Node *temp = headNode;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  while (temp != NULL)
  {
    printf("Age is: %d, Prev is: %d\n", temp->age, temp->prev);
    temp = temp->prev;
  }
}

void insertAt(struct Node **headNode)
{
  int position, age;
  int totalNodes = countNodes(*headNode);
  struct Node *tempHeadNode = *headNode;
  printf("Enter position where you want to insert the NewNod:");
  scanf("%d", &position);
  if (position <= 0 || position > totalNodes + 1)
  {
    printf("Enter Valid Input");
    return;
  }

  printf("Enter the Age: ");
  scanf("%d", &age);
  struct Node *newNode = createNode(age);
  if (position == 1)
  {

    (*headNode)->prev = newNode;
    newNode->next = *headNode;
    *headNode = newNode;
  }
  // if (position == totalNodes + 1)
  // {
  //   while (tempHeadNode->next != NULL)
  //   {
  //     tempHeadNode = tempHeadNode->next;
  //   }
  //   tempHeadNode->next = newNode;
  //   newNode->prev = tempHeadNode;
  //   return;
  // }

  int currentPosition = 1;
  while (position - 1 > currentPosition)
  {
    tempHeadNode = tempHeadNode->next;
    currentPosition++;
  }
  if (position > totalNodes)
  {
    tempHeadNode->next = newNode;
    newNode->prev = tempHeadNode;
  }
  else
  {
    newNode->next = tempHeadNode->next;
    newNode->prev = tempHeadNode;
    tempHeadNode->next->prev = newNode;
    tempHeadNode->next = newNode;
  }
}

void deleteNode(struct Node **headNode)
{
  int position;
  int totalNodes = countNodes(*headNode);
  struct Node *tempHeadNode = *headNode;
  printf("Enter the Node position you want to delete:");
  scanf("%d", &position);

  // Check position is valid or not
  if (position <= 0 || position > totalNodes)
  {
    printf("Invalid Position");
  }

  // If Position is first node
  if (position == 1)
  {
    if (totalNodes == 1)
    {
      free(*headNode);
      *headNode = NULL;
    }
    else
    {
      *headNode = tempHeadNode->next;
      free((*headNode)->prev);
      (*headNode)->prev = NULL;
    }
    return;
  }

  int currentPosition = 1;
  while (position > currentPosition)
  {
    tempHeadNode = tempHeadNode->next;
    currentPosition++;
  }

  struct Node *nodeToDelete = tempHeadNode;
  tempHeadNode->prev->next = tempHeadNode->next;
  if (tempHeadNode->next != NULL)
    tempHeadNode->next->prev = tempHeadNode->prev;
  free(nodeToDelete);
  nodeToDelete = NULL;
  return;
}

void update(struct Node *headNode)
{
  int ch;
  do
  {

    int position;
    int totalNodes = countNodes(headNode);
    printf("Enter the position: ");
    scanf("%d", &position);
    if (position <= 0 || position > totalNodes)
    {
      printf("Please enter a valid Position\n");
    }
    else
    {
      int currentPosition = 1;
      int age;
      struct Node *temp = headNode;
      while (position > currentPosition)
      {
        temp = temp->next;
      }
      printf("Enter age:");
      scanf("%d", &age);
      temp->age = age;
    }
    printf("Enter 0 for update more, otherwise 1: \n");
    scanf("%d", &ch);
  } while (ch == 0);
}

void findByAge(struct Node *headNode)

{

  if (headNode == NULL || headNode->next == NULL)
  {
    printf("List is empty or only one node in it!");
    return;
  }
  int ch;
  do
  {

    int age;
    printf("Enter the age: ");
    scanf("%d", &age);

    struct Node *temp = headNode;
    int currentPosition = 1;
    while (temp != NULL)
    {

      if (age == temp->age)
      {
        printf("Age is %d,  Position is %d\n", temp->age, currentPosition);
        break;
      }
      else
      {
        currentPosition++;
        temp = temp->next;
      }
    }
    if (temp == NULL)
    {
      printf("Enter a valid pisition!\n");
    }

    printf("Enter 0 for update more, otherwise 1: \n");
    scanf("%d", &ch);
  } while (ch == 0);
}

void deleteNodeByAge(struct Node **headNode)
{
  if (*headNode == NULL)
  {
    printf("list is Empty");
    return;
  }

  int age;
  printf("Enter age of you want to delete: ");
  scanf("%d", &age);

  if ((*headNode)->age == age)
  {
    if ((*headNode)->next == NULL)
    {
      free(*headNode);
      *headNode = NULL;
    }
    else
    {
      struct Node *temp = *headNode;
      *headNode = (*headNode)->next;
    
      free(temp);
      temp = NULL;
    }
  }
  else
  {
    struct Node *temp = (*headNode)->next;
    while (temp != NULL && temp->age != age)
    {
      temp = temp->next;
    }
    if (temp == NULL)
    {
      printf("Not age is matched In data");
    }
    else
    {
      struct Node *toDelete = temp;
      temp->prev->next = temp->next;
      free(toDelete);
      toDelete = NULL;
    }
  }
}

int main()
{

  int ch, listChoice;

  while (1)
  {
    printf("\nChoose Linked List to operate on (1 or 2): ");
    scanf("%d", &listChoice);

    struct Node **selectedList = (listChoice == 1) ? &list1 : &list2;

    printf("\n 1. Add Node First");
    printf("\n 2. Add Node Last");
    printf("\n 3. Insert Node at");
    printf("\n 4. Delete Node at");
    printf("\n 5. update Node at");
    printf("\n 6. Print Nodes");
    printf("\n 7. Count Nodes");
    printf("\n 8. reverseList");
    printf("\n 9. DeleteNodeByAge");
    // printf("\n 10. addToSorted");
    // printf("\n 11. checkSorted");
    // printf("\n 12. checkLoop");
    // printf("\n 13. duplicateNode");
    // printf("\n 14. appendList");
    // printf("\n 15. MergSortList");
    printf("\n 10. Exit\n");
    printf("Enter you option: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      addFirst(selectedList);
      break;
    case 2:
      addLast(selectedList);
      break;
    case 3:
      insertAt(selectedList);
      break;
    case 4:
      deleteNode(selectedList);
      break;
    case 5:
      update(*selectedList);
      break;
    case 6:
      printList(*selectedList);
    case 7:
      printf("%d", countNodes(*selectedList));
      break;
    case 8:
      printReverse(*selectedList);
      break;
    case 9:
      deleteNodeByAge(selectedList);
      break;
    // case 10:
    //   addToSorted(selectedList);
    //   break;
    // case 11:
    //   checkSorted(*selectedList);
    //   break;
    // case 12:
    //   checkLoop(*selectedList);
    //   break;
    // case 13:
    //   deleteDuplicate(selectedList);
    //   break;
    // case 14:
    //   appendList(list1, list2);
    //   break;
    // case 15:
    //   mergeSortList(list1, list2);
    //   break;
    case 10:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }
  return 0;
}