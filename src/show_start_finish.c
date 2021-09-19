#include <stdio.h>

void run();
void start();
void template(int start, int finish);
void finish();

int main() {
  run();
  return 0;
}

void run() {
  start();
//  finish();
}

void start() {
  template(0, 2);
  printf(".                                                   ");
  printf("2021 %% school-21 %% team-64 .\n");
  printf(".                                                   ");
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>> .\n");
  printf(".                                                   ");
  printf("dzoraida                   .\n");
  printf(".                                                   ");
  printf("sfirefly                   .\n");
  printf(".                                                   ");
  printf("hrickie                    .\n");
  template(7, 10);
  printf(".                             The Game of Life");
  printf("                                 .\n");
  template(12, 16);
  printf(">              Select the initialization option: [1][2][3][4][5]");
  printf("               <\n");
  template(16, 22);
  printf(">  Exit: [q]                                                     ");
  printf("              <\n");
  template(23, 25);
}

void finish() {
  template(0, 10);
  printf(".                                   Game Over!");
  printf("                                 .\n");
  template(11, 22);
  printf(">  Exit: [q]                                                     ");
  printf("              <\n");
  template(23, 25);
}

void template(int start, int finish) {
  for (int y = start; y < finish; y++) {
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
}
