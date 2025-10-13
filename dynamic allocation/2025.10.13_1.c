#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char no[20];
    char name[50];
    float price;
} Book;

typedef struct
{
    Book* elem;
    int length;
} Sqlist;

Sqlist CreateList(Sqlist L, int n)
{
    int i;
    L.elem = (Book*)malloc(n * sizeof(Book));
    if (L.elem == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%s%s%f", L.elem[i].no, L.elem[i].name, &L.elem[i].price);
        L.length++;
    }
    return L;
}

int main()
{
    int i, n = 2;
    Sqlist L;
    L.length = 0;

    L = CreateList(L, n);

    for (i = 0; i < L.length; i++)
        printf("编号%s 名称%s 价格%f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);

    free(L.elem);
    system("pause");
    return 0;
}