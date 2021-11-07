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

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}


//hàm tính chiều cao của nút có khóa x trong cây T
int hNode(int x, Tree T)
{
    if (T == NULL)
        return -1;
    if (T->Key == x)
    {
        if (T->Left == NULL && T->Right == NULL)
            return 0;
        int l = 0, r = 0;
        if (T->Left != NULL)
            l = hNode(T->Left->Key, T->Left);
        if (T->Right != NULL)
            r = hNode(T->Right->Key, T->Right);
        return Max(l, r)+1;
    }
    else if (T->Key > x)
        return hNode(x, T->Left);
    else
        return hNode(x, T->Right);
}

int main()
{
    Tree T = NULL;
    int x;

    insertNode(27, &T);
    insertNode(12, &T);
    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);

    x = 12;//thay đỏi x để được test case mới
    printf("Chieu cao %d la %d", x, hNode(x, T));
    return 0;
}
