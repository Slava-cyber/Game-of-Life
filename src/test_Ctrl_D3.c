#include <stdio.h>

int main()
{
  char c;
  int i = 0;
  printf("INPUT:\t");
  c = getchar();

  while (c != EOF)
  {
    if (c != '\n')
    {
      ++i;
    }

    c = getchar();
  };

  printf("NUMBER OF CHARACTERS %d.", i);

  return 0;
}