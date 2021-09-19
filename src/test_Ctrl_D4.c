#include <stdio.h>

void input() {
  char c;
  int i = 0;
  printf("INPUT:\t");
  scanf("%d%c", &i, &c);
//  c = getchar();

  while (i == EOF)
  {
//    if (c != '\n')
//    {
//      ++i;
//    }

    scanf("%d%c", &i, &c);
  }

  printf("NUMBER OF CHARACTERS %d.", i);
}

int main()
{
  input();
  printf("Успешно\n");

  return 0;
}