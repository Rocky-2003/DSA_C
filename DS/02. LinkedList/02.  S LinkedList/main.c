#include <stdio.h>
#include <stdlib.h>

struct node
{
  int age;
  struct node *next;
};

struct node *list1 = NULL;
struct node *list2 = NULL;

struct node *addElement(int age)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->age = age;
  newNode->next = NULL;

  // headNode->next->next->next = headNode->next;
  return newNode;
}

void getInput(int *age)
{
  printf("Enter your age: ");
  scanf("%d", age);
}

void addFirst(struct node **headNode)
{
  int res = 1;
  do
  {
    int age;
    getInput(&age);
    struct node *n = addElement(age);
    n->next = *headNode;
    *headNode = n;
    printf("Do you want to add more nodes 0 for yes & 1 for no:");
    scanf("%d", &res);
  } while (res == 0);
}

void addLast(struct node **headNode)
{
  int res = 1;
  do
  {
    int age;
    getInput(&age);
    struct node *n = addElement(age);
    if (*headNode == NULL)
    {
      n->next = *headNode;
      *headNode = n;
    }
    else
    {
      struct node *temp = *headNode;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = n;
    }
    printf("Do you want to add more nodes 0 for yes & 1 for no:");
    scanf("%d", &res);
  } while (res == 0);
}

void printElements(struct node *headNode)
{

  if (headNode == NULL)
  {
    printf("LinkedList is Empty!");
    return;
  }

  struct node *temp = headNode;
  while (temp != NULL)
  {
    printf("Age is: %d\n", temp->age);
    temp = temp->next;
  }
}

int countLength(struct node *headNode)
{
  struct node *temp = headNode;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }

  printf("Total no. of count is: %d\n", count);
  return count;
}

void insertAt(struct node **headNode)
{
  int age, i, position;
  int leng = countLength(*headNode);
  printf("Enter position where to insert: ");
  scanf("%d", &position);

  if (position < 1 || position >= leng + 1)
  {
    printf("Invalid position!");
    return;
  }

  getInput(&age);
  struct node *n = addElement(age);
  if (position == 1)
  {
    n->next = *headNode;
    *headNode = n;
    return;
  }

  struct node *temp = *headNode;
  for (i = 1; i < position - 1; i++)
  {
    temp = temp->next;
  }

  n->next = temp->next;
  temp->next = n;
}

void deleteNode(struct node **headNode)
{
  int position;
  int totalNodes = countLength(*headNode);
  printf("Enter the Position to Delete  Node: ");
  scanf("%d", &position);

  if (position <= 0 || position > totalNodes)
  {
    printf("Invalid Position🔥🔥🔥");
    return;
  }

  if (position == 1)
  {
    struct node *temp = (*headNode)->next;
    *headNode = (*headNode)->next;
    free(temp);
    temp = NULL;
    return;
  }
  else
  {
    int livePosition = 1;
    struct node *temp = *headNode;
    while (position - 1 > livePosition)
    {
      temp = temp->next;
      livePosition++;
    }

    struct node *ptrToDelete = temp->next;
    temp->next = temp->next->next;
    free(ptrToDelete);
    ptrToDelete = NULL;
    return;
  }
}

void update(struct node **headNode)
{
  int position, age;
  int livePosition = 1;
  printf("Enter Position: ");
  scanf("%d", &position);
  int totalNodes = countLength(*headNode);

  if (position <= 0 || position > totalNodes)
  {
    printf("Invalid position try again!\n");
    return;
  }

  struct node *temp = *headNode;

  while (position > livePosition)
  {
    temp = temp->next;
    livePosition++;
  }

  printf("Enter new Age: ");
  scanf("%d", &age);
  temp->age = age;
}

void reverseList(struct node **headNode)
{

  struct node *currentNode = *headNode;
  struct node *nextNode;
  struct node *lastNode;

  do
  {

    nextNode = currentNode->next;
    currentNode->next = lastNode;
    lastNode = currentNode;
    currentNode = nextNode;
  } while (currentNode != NULL);
  *headNode = lastNode;
};

void reverseListBeforeEnd(struct node **headNode)
{

  struct node *currentNode = *headNode;
  struct node *nextNode;
  struct node *lastNode = *headNode;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  do
  {

    nextNode = currentNode->next;
    currentNode->next = lastNode;
    lastNode = currentNode;
    currentNode = nextNode;
  } while (currentNode->next != NULL);
  *headNode = lastNode;
};

void deleteNodeByAge(struct node **headNode)
{
  if (*headNode == NULL)
  {
    printf("List is Empty!\n");
    return;
  }

  int age;
  printf("Enter age to delete Node: ");
  scanf("%d", &age);

  if (age <= 0)
  {
    printf("Enter a valid Age\n");
    return;
  }

  struct node *temp = *headNode;
  struct node *beforeTemp = NULL;

  // If the head node itself holds the age to be deleted
  if ((*headNode)->age == age)
  {
    temp = *headNode;              // Store the current head
    *headNode = (*headNode)->next; // Move head to the next node
    free(temp);                    // Free the old head
    printf("Node with age %d deleted (Head Node).\n", age);
    return;
  }

  // Traverse the list to find the node to delete
  while (temp != NULL && temp->age != age)
  {
    beforeTemp = temp; // Track the node before the one to delete
    temp = temp->next;
  }

  // If the node with the given age is not found
  if (temp == NULL)
  {
    printf("Node with age %d not found.\n", age);
    return;
  }

  // Node found; unlink it from the list
  beforeTemp->next = temp->next;
  free(temp); // Free the memory of the node to delete
  printf("Node with age %d deleted.\n", age);
}

void addToSorted(struct node **headNode)
{
  if (*headNode == NULL)
  {
    printf("List is Empty!");
    return;
  }
  int age;
  printf("Enter the age of new node:");
  scanf("%d", &age);

  struct node *newNode = addElement(age);
  struct node *temp = *headNode;
  struct node *beforeTemp;

  while (temp != NULL && temp->age < newNode->age)
  {
    beforeTemp = temp;
    temp = temp->next;
  }

  if (temp == *headNode)
  {
    newNode->next = *headNode;
    *headNode = newNode;
  }
  else
  {
    newNode->next = temp;
    beforeTemp->next = newNode;
  }
}

int checkSorted(struct node *headNode)
{

  if (headNode == NULL || headNode->next == NULL)
  {

    printf("sorted");
    return 1;
  }

  struct node *temp = headNode;
  while (temp->next != NULL)
  {
    if (temp->age >= temp->next->age)
    {
      printf("Not sorted");
      return 0;
    }
    temp = temp->next;
  }
  printf("sorted");
  return 1;
}

void checkLoop(struct node *headNode)
{
  if (headNode == NULL)
  {
    printf("List is Empty!");
  }
  else if (headNode->next == NULL)
  {
    printf("Only one Node is in the List!");
  }
  else
  {
    struct node *temp, *temp1;
    temp = temp1 = headNode;
    while (temp != NULL && temp && temp1)
    {
      temp = temp->next;
      temp1 = temp1->next;
      if (temp1 != NULL)
        temp1 = temp1->next;
    }

    if (temp == temp1)
      printf("There is Loop in list!");
    else
      printf("Tere is no Loop in List!");
  }
}

void deleteDuplicate(struct node **headNode)
{
  if (*headNode == NULL)
  {
    printf("List is Empty");
    return;
  }

  if ((*headNode)->next == NULL)
  {
    printf("No Duplicate Node");
  }
  else
  {
    struct node *temp, *temp1, *beforeTemp1;
    struct node *toDeleteDuplicate = NULL;
    temp = *headNode;

    while (temp != NULL)
    {
      temp1 = temp->next;
      while (temp1 != NULL)
      {
        if (temp1->age == temp->age)
        {
          printf("temp is :%d, temp1 is :%d", temp->age, temp1->age);
          beforeTemp1->next = temp1->next;
          toDeleteDuplicate = temp1;
          temp1 = temp1->next;
          break;
        }
        beforeTemp1 = temp1;
        temp1 = temp1->next;
      }

      temp = temp->next;
    }
  }
}
void deleteDuplicateLastOcurence(struct node **headNode)
{
  if (*headNode == NULL)
  {
    printf("List is Empty");
    return;
  }

  if ((*headNode)->next == NULL)
  {
    printf("No Duplicate Node");
    return;
  }

  struct node *temp, *temp1, *beforeTemp1;
  struct node *toDeleteDuplicate = NULL;
  temp = *headNode;

  while (temp != NULL)
  {
    if (temp->next != NULL)
    {
      temp1 = temp->next;
    }
    else
    {
      return;
    }

    while (temp1 != NULL)
    {
      if (temp1->age == temp->age && temp1->age != temp1->next->age)
      {
        printf("temp is :%d, temp1 is :%d\n", temp->age, temp1->age);
        beforeTemp1->next = temp1->next;
        toDeleteDuplicate = temp1;
        temp1 = temp1->next;
        break;
      }
      else
      {
        beforeTemp1 = temp1;
        temp1 = temp1->next;
      }
    }
    if (toDeleteDuplicate != NULL)
    {
      free(toDeleteDuplicate);
      toDeleteDuplicate = NULL;
      temp = temp1;
    }
    else
    {

      temp = temp->next;
    }
  }
  return;
}

void appendList(struct node *list1, struct node *list2)
{
  if (list1 == NULL || list2 == NULL)
  {
    return;
  }
  struct node *temp = list1;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = list2;
}

void mergeSortList(struct node *headNode1, struct node *headNode2)
{
  struct node *start1 = headNode1;
  struct node *start2 = headNode2;

  struct node *start, *last;
  if (start1->age < start2->age)
  {
    start = start1;
    last = start1;
    start1 = start1->next;
    last->next = NULL;
  }
  else
  {
    start = start2;
    last = start2;
    start2 = start2->next;
    last->next = NULL;
  }

  while (start1 && start2)
  {
    if (start1->age < start2->age)
    {
      last->next = start1;
      last = start1;
      start1 = start1->next;
      last->next = NULL;
    }
    else
    {
      last->next = start2;
      last = start2;
      start2 = start2->next;
      last->next = NULL;
    }
  }

  if ((start1))
  {
    last->next = (start1);
  }
  if (start2)
  {
    last->next = (start2);
  }
  printElements(start);
}

int main()
{

  int ch, listChoice;

  while (1)
  {
    printf("\nChoose Linked List to operate on (1 or 2): ");
    scanf("%d", &listChoice);

    struct node **selectedList = (listChoice == 1) ? &list1 : &list2;

    printf("\n 1. Add Node First");
    printf("\n 2. Add Node Last");
    printf("\n 3. Insert Node at");
    printf("\n 4. Delete Node at");
    printf("\n 5. update Node at");
    printf("\n 6. Print Nodes");
    printf("\n 7. Count Nodes");
    printf("\n 8. reverseList");
    printf("\n 9. DeleteNodeByAge");
    printf("\n 10. addToSorted");
    printf("\n 11. checkSorted");
    printf("\n 12. checkLoop");
    printf("\n 13. duplicateNode");
    printf("\n 14. appendList");
    printf("\n 15. MergSortList");
    printf("\n 16. deleteDuplicateLastOcurence");
    printf("\n 17. reverseListBeforeEnd");
    printf("\n 18. Exit\n");
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
      update(selectedList);
      break;
    case 6:
      printElements(*selectedList);
    case 7:
      printf("%d", countLength(*selectedList));
      break;
    case 8:
      reverseList(selectedList);
      break;
    case 9:
      deleteNodeByAge(selectedList);
      break;
    case 10:
      addToSorted(selectedList);
      break;
    case 11:
      checkSorted(*selectedList);
      break;
    case 12:
      checkLoop(*selectedList);
      break;
    case 13:
      deleteDuplicate(selectedList);
      break;
    case 14:
      appendList(list1, list2);
      break;
    case 15:
      mergeSortList(list1, list2);
      break;
    case 16:
      deleteDuplicateLastOcurence(selectedList);
      break;
    case 17:
      reverseListBeforeEnd(selectedList);
      // reverseListBeforeEnd();
      break;
    case 18:
      return 0;
      break;

    default:
      printf("Invalid Input");
      break;
    }
  }

  return 0;
}
