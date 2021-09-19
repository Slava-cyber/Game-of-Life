#include <stdio.h>
 
int main() {
    int m = 25, n = 80;
    char A[m][n];

    FILE *fp;
    fp = fopen("start1.txt", "r");

    if (fp == NULL) {
        puts("Open file error");
        return 0;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fscanf(fp, "%c", &A[i][j]);
            }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (j == n - 1){
            printf("%c\n", A[i][j]);
            }
            else {
                printf("%c", A[i][j]);
            }
        }
    }
    fclose(fp);
    return 0;
}
/* код для вставки в generate основной код (изменить константы на @ и " ")
FILE *fp;
fp = fopen("out.txt", "r");

if (fp == NULL) {
    puts("Open file error");
    return 0;
}

for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        fscanf(fp, "%c", &a[i][j]);
        }
}

fclose(fp);
*/
