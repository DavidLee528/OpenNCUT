/*
 * @ Author: 李天昊
 * @ Description: 调用库函数qsort()对数据个位数升序排列 / 函数指针练习
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */
#include<stdio.h>
#include<stdlib.h> 
#define MAX_NUM 100

int MyCmp(const void *n1, const void *n2); 

int main() {
    unsigned int arr[MAX_NUM] = {8, 1234, 3, 21, 90, 76, 11}; 
    int (*cmp)(const void *n1, const void *n2); 
    cmp = MyCmp; 
    qsort(arr, 7, sizeof(unsigned int), cmp); 
    for (int i = 0; i < 7; i++) {
        printf("%d ", *(arr + i)); 
    }
    return 0; 
}

int MyCmp(const void *n1, const void *n2) {
    unsigned int *p1; 
    unsigned int *p2; 
    p1 = (unsigned int *)n1; 
    p2 = (unsigned int *)n2; 
    return (*p1 % 10) - (*p2 % 10); 
}