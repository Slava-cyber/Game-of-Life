#include <stdio.h>

void run();
void start();

int main() {
  run();
  return 0;
}

void run() {
  start();
}

 void start() {
   for (int y = 0; y < 10; y++) {
     for (int x = 0; x < 80; x++) {
       if (y == 0 || y == 24) {
         printf("-");
       } else if (x == 0 || x == 79) {
         printf(".");
       } else {
         printf(" ");
       }
     }
     printf("\n");
   }
   printf(">                Выберите вариант инициализации: [1][2][3][4][5]               <\n");
}