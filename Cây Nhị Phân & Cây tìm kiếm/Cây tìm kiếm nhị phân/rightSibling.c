#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{

    int Key;

    struct Node *Left, *Right;
};
typedef struct Node *Tree;

void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}

void postOder(Tree T)
{
    if (T != NULL)
    {
        postOder(T->Left);
        postOder(T->Right);
        printf("%d ", T->Key);
    }
}

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


//hàm tìm kiếm nút anh em ruột phải của nút có khóa x trong cây tìm kiếm nhị phânphân
Tree rightSibling(int x, Tree T)
{
    Tree P = T;
    Tree broTher = NULL;
    while (P != NULL)
    {
        if (P->Key == x)
            if (P != broTher)
                return broTher;
            else
                return NULL;
        broTher = P->Right;
        if (P->Key > x)
            P = P->Left;
        else
            P = P->Right;
    }
    return NULL;
}

int main()
{
    Tree T = NULL;
    Tree p;
    int x;

    insertNode(27, &T);
    insertNode(12, &T);
    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);
    x = 21;//thay đổi x để được test case mới

    p = rightSibling(x, T);
    if (p == NULL)
        printf("Anh em ruot phai khong co hoac khong hop le");
    else
        printf("Nut anh em ruot phai la %d", p->Key);
    return 0;
}
