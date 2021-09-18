#include <stdio.h>
#define N 25
#define M 80

int neighbor(int a[N][M], int b[N][M], int n , int m);
int neighbor_number(int a[N][M], int x, int y);
int x_neighbor(int x, int step);
int y_neighbor(int y, int step);
int draw(int a[N][M], int n, int m);
int recoder(int a[N][M], int b[N][M], int n, int m);
int stop_or_go(int a[N][M], int b[N][M], int n, int m);
int neighbor_change(int a[N][M], int b[N][M], int n , int m);
int generate(int a[N][M], int n, int m);
int generate2(int a[N][M], int n, int m);

int main() {
    int first[N][M], second[N][M];
    int flag = 1;
    char ch1, ch2;
    int init = 1;
    generate2(first, N ,M);
    generate(second, N, M);
    printf("\033[H\033[J");
    draw(second, N, M);
    while(flag) {
        if (stop_or_go(first, second, N , M)) {
            recoder(second, first, N, M);
            if (scanf("%c%c", &ch1, &ch2) == 2 && ch1 == ' ' && ch2 == '\n') {
                neighbor_change(first, second, N, M);
                printf("\033[H\033[J");
                draw(second, N, M);
            }
        } else {
            printf("\033[H\033[J");
            printf("stop_game");
            flag = 0;
        }
    }
    return 0;
}

int stop_or_go(int a[N][M], int b[N][M], int n, int m) {
    int k = 0;
    int k1 = 0;
    int k2 = 0;
    int flag;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(*(b + i) + j) == 1) {
                k++;
            }
            if (*(*(b + i) + j) == 0) {
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

int neighbor_change(int a[N][M], int b[N][M], int n , int m) {
    int bufer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bufer = neighbor_number(a, j, i);
            //printf("%ds", bufer);
            if (bufer == 3) {
                *(*(b + i) + j) = 1;
            } else if (bufer == 2) {
                *(*(b + i) + j) = *(*(a + i) + j);
            } else {
                *(*(b + i) + j) = 0;
            }
        }
        //printf("\n");
    }
    return 1;
}

int neighbor_number(int a[N][M], int x, int y) {
    int right = x_neighbor(x, 1);
    int left = x_neighbor(x, -1);
    int up = y_neighbor(y, -1);
    int down = y_neighbor(y, 1);
    int k = 0;
    if (*(*(a + y) + right) == 1) {
        k++;
    }
    if (*(*(a + y) + left) == 1) {
        k++;
    }
    if (*(*(a + up) + right) == 1) {
        k++;
    }
    if (*(*(a + up) + left) == 1) {
        k++;
    }
    if (*(*(a + up) + x) == 1) {
        k++;
    }
    if (*(*(a + down) + right) == 1) {
        k++;
    }
    if (*(*(a + down) + left) == 1) {
        k++;
    }
    if (*(*(a + down) + x) == 1) {
        k++;
    }
    return k;
}

int x_neighbor(int x, int step) {
    int x_new = x + step;
    if (x_new > 79) {
        x_new = 0;
    } else if (x_new < 0) {
        x_new = 79;
    }
    return x_new;
}

int y_neighbor(int y, int step) {
    int y_new = y + step;
    if (y_new > 24) {
        y_new = 0;
    } else if (y_new < 0) {
        y_new = 24;
    }
    return y_new;
}


int draw(int a[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            printf("%d", *(*(a + i) + j));
        }
    printf("\n");
    }
    return 1;
}

int recoder(int a[N][M], int b[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(b + i) + j) = *(*(a + i) + j);
        }
    }
    return 1;
}

int generate(int a[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(a + i) + j) = 0;
        }
    }
    /*a[5][5] = 1;
    a[5][6] = 1;
    a[6][5] = 1;
    a[6][6] = 1;
    a[7][5] = 1;*/
    a[0][1] = 1;
    a[0][2] = 1;
    a[0][3] = 1;
    a[24][2] = 1;
    a[24][3] = 1;
    return 1;
}

int generate2(int a[N][M], int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            *(*(a + i) + j) = 0;
        }
    }
    return 1;
}
