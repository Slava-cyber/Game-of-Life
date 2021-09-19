#include <stdio.h>

void input();

int main()
{
  input();
}

void input() {
//  int c;
  char c = 'd';
  do {
    if( (c = getchar()) == EOF ) {
      input();
    }
//    scanf("%c", &c);
  } while (c != ' ');
  printf("Успешно %c\n", c);
//  while((c = getchar()) == EOF)
//  {
//    if( getchar() == EOF ) {
//      input();
//    }
//      break;
//    printf(" %d\n", c);
//  }
//  printf("%d %u %x- at EOF\n", c , c, c);
//  input();
}
