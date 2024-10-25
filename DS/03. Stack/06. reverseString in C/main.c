#include <stdio.h>
#include <string.h>

char str[30] = "a*b+d/c+h";
void reverseString()
{
  int i, l;
  l = strlen(str);

  for (i = 0; i < l / 2; i++)
  {
    char ch = str[i];
    str[i] = str[l - i - 1];
    str[l - i - 1] = ch;
  }
}

int main()
{
  reverseString();
  printf("%s", str);
}