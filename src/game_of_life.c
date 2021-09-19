#include <stdio.h>
#define N 25
#define M 80

const char cell = '*';
const char empty = '-';

int neighbor(char a[N][M], char b[N][M], int n , int m);
int neighbor_number(char a[N][M], int x, int y);
int x_neighbor(int x, int step);
int y_neighbor(int y, int step);
int draw(char a[N][M], int n, int m);
int recoder(char a[N][M], char b[N][M], int n, int m);
int stop_or_go(char a[N][M], char b[N][M], char c[N][M], int n, int m);
int neighbor_change(char a[N][M], char b[N][M], int n , int m);
int generate(char a[N][M], int n, int m);
int input(char a[N][M], int n, int m, int type);
int finish();
int template(int start, int finish);
int start();
int run(char first[N][M], char second[N][M], char third[N][M]);
int choice(int *type, int *flag);
int game_of_life(int flag, char a[N][M], char b[N][M], char c[N][M]);

int main() {
    char first[N][M], second[N][M], third[N][M];
    run(first, second, third);
    return 0;
}

// checking the condition of the game.
int stop_or_go(char a[N][M], char b[N][M], char c[N][M], int n, int m) {
    int k = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    int flag;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(*(b + i) + j) == cell) {
                k++;
            }
            if (*(*(b + i) + j) == empty) {
                k1++;
            }
            if (*(*(b + i) + j) == *(*(a + i) + j)) {
                k2++;
            }
            if (*(*(b + i) + j) == *(*(c + i) + j)) {
                k3++;
            }
            if (*(*(a + i) + j) == empty) {
                k4++;
            }
        }
    }
    if (k == n * m || k1 == n * m || k2 == n * m || (k3 == n * m && k4 != n * m)) {
        flag = 0;
    } else {
        flag = 1;
    }
    return flag;
}

// change the matrix
int neighbor_change(char a[N][M], char b[N][M], int n , int m) {
    int bufer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bufer = neighbor_number(a, j, i);
            if (bufer == 3) {
                *(*(b + i) + j) = cell;
            } else if (bufer == 2) {
                *(*(b + i) + j) = *(*(a + i) + j);
            } else {
                *(*(b + i) + j) = empty;
            }
        }
    }
    return 1;
}

// count neighbors for certain point
int neighbor_number(char a[N][M], int x, int y) {
    int right = x_neighbor(x, 1);
    int left = x_neighbor(x, -1);
    int up = y_neighbor(y, -1);
    int down = y_neighbor(y, 1);
    int k = 0;
    if (*(*(a + y) + right) == cell) {
        k++;
    }
    if (*(*(a + y) + left) == cell) {
        k++;
    }
    if (*(*(a + up) + right) == cell) {
        k++;
    }
    if (*(*(a + up) + left) == cell) {
        k++;
    }
    if (*(*(a + up) + x) == cell) {
        k++;
    }
    if (*(*(a + down) + right) == cell) {
        k++;
    }
    if (*(*(a + down) + left) == cell) {
        k++;
    }
    if (*(*(a + down) + x) == cell) {
        k++;
    }
    return k;
}

// check x-axis neighbors
int x_neighbor(int x, int step) {
    int x_new = x + step;
    if (x_new > 79) {
        x_new = 0;
    } else if (x_new < 0) {
        x_new = 79;
    }
    return x_new;
}

// check y-axis neighbors
int y_neighbor(int y, int step) {
    int y_new = y + step;
    if (y_new > 24) {
        y_new = 0;
    } else if (y_new < 0) {
        y_new = 24;
    }
    return y_new;
}

// just draw matrix
int draw(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", *(*(a + i) + j));
        }
    printf("\n");
    }
    return 1;
}

// overwrite the previous step to the previous one
int recoder(char a[N][M], char b[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(b + i) + j) = *(*(a + i) + j);
        }
    }
    return 1;
}

int generate(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(a + i) + j) = empty;
        }
    }
    return 1;
}

int input(char a[N][M], int n, int m, int type) {
    int flag = 1;
    char teamp;
    FILE *fp;
    if (type == 1) {
        fp = fopen("gun_grospera.txt", "r");
    } else if (type == 2) {
        fp = fopen("oscilyator.txt", "r");
    } else if (type == 3) {
        fp = fopen("parovoz.txt", "r");
    } else if (type == 4) {
        fp = fopen("r_pentomino.txt", "r");
    } else if (type == 5) {
        fp = fopen("naturmort.txt", "r");
    } else if (type == 6) {
        fp = fopen("g-over.txt", "r");
    } else {
        fp = fopen("cycle.txt", "r");
    }
    if (fp == NULL) {
        puts("Open file error");
        flag = 0;
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fscanf(fp, "%c", &teamp);
                if (teamp != '\n') {
                    a[i][j] = teamp;
                } else {
                    j--;
                }
            }
        }
        fclose(fp);
    }
    return flag;
}

int choice(int *type, int *flag) {
    char ch;
    if (scanf("%d%c", type, &ch) == 2 && *type >= 1 && *type <=7 && ch == '\n') {
            *flag = 1;
    } else {
        printf("Wrong file name, this file type doesn't exist");
        *flag = 0;
    }
    return *flag;
}

int run(char first[N][M], char second[N][M], char third[N][M]) {
    int type, flag;
    start();
    if (choice(&type, &flag)) {
        generate(first, N, M);  // generate initial matrix can be deleted
        input(second, N, M, type);
        recoder(second, third, N, M);
        printf("\033[H\033[J");
        draw(second, N, M);  // initial draw can be changed
        game_of_life(flag, first, second, third);  // game proccess
    }
    return 0;
}

int game_of_life(int flag, char a[N][M], char b[N][M], char c[N][M]) {
    char ch;
    while (flag) {
        if (stop_or_go(a, b, c, N , M)) {  // checking the condition of the game
            recoder(b, a, N, M);  // owerwrite previous step to the previous one
            do {  // control the input symbol
                // scanf("%c", &ch);  // input char
                if ((ch = getchar()) == EOF) {
                    break;
                }
                while ((getchar() != '\n')) {}
                if (ch == 'q') {
                    break;
                }
                printf("\033[H\033[J");  // clear window
                draw(a, N, M);   // just draw what we have until necessary symbol
            } while (ch != ' ');
                if (ch == ' ') {
                    neighbor_change(a, b, N, M);  // changing the matrix
                    printf("\033[H\033[J");
                    draw(b, N, M);
                } else {
                    printf("\033[H\033[J");
                    printf("stop_game");
                    flag = 0;  // exit from cycle
                }
        } else {  // if game is stopped
            printf("\033[H\033[J");
            finish();
            flag = 0;  // exit from cycle
        }
    }
    return 1;
}

int start() {
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
  return 1;
}

int finish() {
  template(0, 10);
  printf(".                                   Game Over!");
  printf("                                 .\n");
  template(11, 22);
  printf(">  Exit: [q]                                                     ");
  printf("              <\n");
  template(23, 25);
  return 1;
}

int template(int start, int finish) {
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
  return 1;
}
