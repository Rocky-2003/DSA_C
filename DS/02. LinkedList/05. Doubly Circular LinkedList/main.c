#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{

  int age;
  // char name[10];

  struct Node *next;
  struct Node *prev;
};

struct Node *list1 = NULL;
struct Node *list2 = NULL;
struct Node *addNode(int age)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->age = age;
  // newNode->name = name;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

void addFirst(struct Node **headNode)
{
  int ch = 1;
  do
  {

    int age;
    // char name[10];

    printf("Enter the age: \n");
    scanf("%d", &age);
    // printf("Enter the name: ");
    // scanf("%d", &name);
    struct Node *newNode = addNode(age);
    if (*headNode == NULL)
    {
      newNode->next = newNode->prev = *headNode = newNode;
    }
    else
    {
      newNode->next = *headNode;
      newNode->prev = (*headNode)->prev;
      (*headNode)->prev->next = newNode;
      (*headNode)->prev = newNode;
    }

    printf("Enter 0 for more nodes to add, otherwise 1:-  ");
    scanf("%d", &ch);
  } while (ch == 0);
}

int countNodes(struct Node *headNode)
{
  if (headNode == NULL)
  {
    printf("List is Empty!\n");
    return 0;
  }

  struct Node *temp = headNode;
  int totalNodes = 1;
  while (temp->next != headNode)
  {
    temp = temp->next;
    totalNodes++;
  }
  printf("TotalNodes are: %d\n", totalNodes);
  return totalNodes;
}

void printNodes(struct Node *headNode)
{
  if (headNode == NULL)
  {
    printf("List is empty!\n");
  }
  else
  {

    struct Node *temp = headNode;
    do
    {
      printf("Age is: %d\n", temp->age);
      temp = temp->next;
    } while (temp != headNode);
  }
}

void printNodesBackward(struct Node *headNode)
{
  if (headNode == NULL)
  {
    printf("List is empty!\n");
  }
  else
  {

    struct Node *temp = headNode->prev;
    do
    {
      printf("Age is: %d\n", temp->age);
      temp = temp->prev;
    } while (temp != headNode->prev);
  }
}

void insertAt(struct Node **headNode)
{
  int totalNodes = countNodes(*headNode);
  int position, age;

  printf("Enter the position where you want to add Node:\n");
  scanf("%d", &position);
  if (position <= 0 || position > totalNodes + 1)
  {
    printf("Please enter a valid poistion!\n");
    return;
  }

  printf("Enter the age:\n");
  scanf("%d", &age);
  struct Node *nodeToInsert = addNode(age);

  if (position == 1)
  {
    struct Node *temp = *headNode;
    nodeToInsert->next = temp;
    nodeToInsert->prev = temp->prev;
    temp->prev->next = nodeToInsert;
    temp->prev = nodeToInsert;
    *headNode = nodeToInsert;
  }
  else
  {
    struct Node *temp = *headNode;
    for (int i = 1; i < position - 1; i++)
    {
      temp = temp->next;
    }

    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
  }
}

void deleteNode(struct Node **headNode)
{
  int totalNodes = countNodes(*headNode);
  int position;

  printf("Enter the position of node you want to delete: \n");
  scanf("%d", &position);

  if (position <= 0 || position > totalNodes)
  {
    printf("Please enter a valid Position\n");
    return;
  }
  struct Node *nodeToDelete = *headNode;

  if (totalNodes == 1 && position == 1)
  {
    free(*headNode);
    *headNode = NULL;
  }
  else
  {
    for (int i = 1; i < position; i++)
    {
      nodeToDelete = nodeToDelete->next;
    }
    nodeToDelete->next->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    if (position == 1)
      *headNode = nodeToDelete->next;
    free(nodeToDelete);
    nodeToDelete = NULL;
  }
}

void reverseList(struct Node **headNode)
{

  if (*headNode == NULL || (*headNode)->next == *headNode)
  {
    printf("List is Empty! or only one element");
  }
  else
  {

    struct Node *ptr = *headNode;
    struct Node *temp;
    do
    {
      temp = ptr->prev;
      ptr->prev = ptr->next;
      ptr->next = temp;

      ptr = ptr->prev;

    } while (ptr != *headNode);

    if (temp != NULL)
    {
      *headNode = temp->prev;
    }
  }
}

void addLast(struct Node **headNode) {}

void update(struct Node *headNode) {}

void deleteNodeByAge(struct Node **headNode)b
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
    if ((*headNode)->next == NULL || (*headNode)->next == *headNode || (*headNode)->prev==*headNode)
    {
      free(*headNode);
      *headNode = NULL;
    }
    else
    {
      struct Node *temp = *headNode;
      *headNode = (*headNode)->next;
      (*headNode)->prev = temp->prev;
      free(temp);
      temp = NULL;
    }
  }
  else
  {
    struct Node *temp = (*headNode);
    while (temp->next != *headNode && temp->age != age)
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
      temp->next->prev = temp->prev;
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
    printf("\n 10. delete Node by age\n");
    printf("\n 11. Exit\n");
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
      printNodes(*selectedList);
    case 7:
      printf("%d", countNodes(*selectedList));
      break;
    case 8:
      printNodesBackward(*selectedList);
      break;
    case 9:
      deleteNodeByAge(selectedList);
      break;
    case 10:
      reverseList(selectedList);
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
    case 11:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }
  return 0;
}