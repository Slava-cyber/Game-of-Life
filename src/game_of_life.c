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
int stop_or_go(char a[N][M], char b[N][M], int n, int m);
int neighbor_change(char a[N][M], char b[N][M], int n , int m);
int generate(char a[N][M], int n, int m);
int generate2(char a[N][M], int n, int m);
int input(char a[N][M], int n, int m);

int main() {
    char first[N][M], second[N][M];
    int flag = 1;
    char ch;
    generate2(first, N ,M); // generate initial matrix can be deleted
    //generate(second, N, M);
    input(second, N, M);
    printf("\033[H\033[J");
    draw(second, N, M);  // initial draw can be changed
    while(flag) {
        if (stop_or_go(first, second, N , M)) { // checking the condition of the game
            recoder(second, first, N, M); // owerwrite previous step to the previous one
            do { // control the input symbol
                scanf("%c", &ch); // input char
                while ((getchar() != '\n')) {}
                printf("\033[H\033[J"); // clear window
                draw(second, N, M);  // just draw what we have until necessary symbol
            } while (ch != ' ');
                neighbor_change(first, second, N, M); // changing the matrix
                printf("\033[H\033[J");
                draw(second, N, M);
        } else { // if game is stopped
            printf("\033[H\033[J");
            printf("stop_game");
            flag = 0; // exit from cycle
        }
    }
    return 0;
}

// checking the condition of the game.
int stop_or_go(char a[N][M], char b[N][M], int n, int m) {
    int k = 0;
    int k1 = 0;
    int k2 = 0;
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
        }
    }
    if (k == n * m || k1 == n * m || k2 == n * m) {
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
            //printf("%ds", bufer);
            if (bufer == 3) {
                *(*(b + i) + j) = cell;
            } else if (bufer == 2) {
                *(*(b + i) + j) = *(*(a + i) + j);
            } else {
                *(*(b + i) + j) = empty;
            }
        }
        //printf("\n");
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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            printf("%c", *(*(a + i) + j));
        }
    printf("\n");
    }
    return 1;
}

// overwrite the previous step to the previous one
int recoder(char a[N][M], char b[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(b + i) + j) = *(*(a + i) + j);
        }
    }
    return 1;
}


int generate(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(a + i) + j) = empty;
        }
    }
    /*a[5][5] = 1;
    a[5][6] = 1;
    a[6][5] = 1;
    a[6][6] = 1;
    a[7][5] = 1;*/
    a[0][1] = cell;
    a[0][2] = cell;
    a[0][3] = cell;
    a[24][2] = cell;
    a[24][3] = cell;
       a[0][1] = cell;
    a[3][2] = cell;
    a[3][3] = cell;
    a[4][4] = cell;
    a[4][3] = cell;
    a[4][6] = cell;
    a[6][5] = cell;
    a[7][4] = cell;
    a[8][6] = cell;
    a[7][5] = cell;
    a[2][3] = cell;
    a[14][12] = cell;
    a[13][12] = cell;
    a[15][13] = cell;
    a[16][13] = cell;
    a[17][18] = cell;
    a[18][19] = cell;
    a[23][20] = cell;
    a[23][34] = cell;
    a[24][35] = cell;
    a[24][35] = cell;
    return 1;
}

int generate2(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(a + i) + j) = empty;
        }
    }
    return 1;
}

int input(char a[N][M], int n, int m) {
    int flag = 1;
    FILE *fp;
    fp = fopen("gun_grospera.txt", "r");
    char temp;
    if (fp == NULL) {
        puts("Open file error");
        flag = 0;
    }
    if(flag == 1) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fscanf(fp, "%c", &temp);
            if(temp != '\n') {
                a[i][j] = temp;
            }
            else {
            //    test = 1;
                j--;
            }
        }
    }
    }
    fclose(fp);
    return flag;
}
