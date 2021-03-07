#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>int main(){    int A, B;    scanf("%d%d", &A, &B);    int i = 1;    while (((A * i) % B) != 0)    {i++;    }    printf("%d\n", A*i);    return 0;}