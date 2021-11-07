#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{
    int Key;
    struct Node *Left, *Right;
};

typedef struct Node *Tree;

void insertNode(int X, Tree *pT)
{
    if ((*pT) == NULL)
    {
        (*pT) = (struct Node *)malloc(sizeof(struct Node));
        (*pT)->Key = X;
        (*pT)->Left = NULL;
        (*pT)->Right = NULL;
    }
    else if (X < (*pT)->Key)
        insertNode(X, &((*pT)->Left));
    else if (X > (*pT)->Key)
        insertNode(X, &((*pT)->Right));
}


//hàm tìm kiếm khóa x trong cây tìm kiếm nhị phân
Tree searchNode(int x, Tree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Key == x)
        return T;
    else if (T->Key < x)
        return searchNode(x, T->Right);
    else
        return searchNode(x, T->Left);
}

int main()
{
    Tree T = NULL;
    Tree p;

    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);

    p = searchNode(20, T);
    if (p == NULL)
        printf("Khong thay");
    else
        printf("Tim thay");
}
