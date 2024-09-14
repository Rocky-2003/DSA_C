#include <stdio.h>
#include <string.h>

struct Student
{
  int rollNo;
  char name[20];
  int marks;
  
  /* data */
};

int main(){
  struct Student a;

  a.marks = 200;
  a.rollNo = 22;
  strcpy(a.name, "RockyMor");
  // printf("%d\n", sizeof(a));
  printf("%d\n%s\n%d", a.rollNo, a.name, a.marks);
  return 0;
};
 