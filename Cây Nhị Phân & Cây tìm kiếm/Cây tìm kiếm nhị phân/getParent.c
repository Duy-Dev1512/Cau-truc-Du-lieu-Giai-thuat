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


//hàm tìm kiếm nút cha của nút có khóa x trong cây 
Tree getParent(int x, Tree T)
{
    Tree P = T, Parent = NULL;
    while (P != NULL)
    {
        if (P->Key == x)
            return Parent;
        Parent = P;
        if (P->Key < x)
            P = P->Right;
        else
            P = P->Left;
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
    x = 12;

    x = 12;
    p = getParent(x, T);
    if (p == NULL)
        printf("Cha khong co hoac khong hop le");
    else
        printf("Nut cha la %d", p->Key);    
    return 0;
}
