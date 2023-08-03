#include<stdio.h>

void multiplication(int x, int y);

int main() {
    int i=1, j=1;
    while(i <= 9) {
        while(j <= 9) {
            multiplication(i, j);
            j++;
        }
        i++;
        j = 1;
        printf("\n");
    }
    return 0;
}

void multiplication(int x,int y) {
    printf("%d*%d=%d ", x, y, x * y);
}
