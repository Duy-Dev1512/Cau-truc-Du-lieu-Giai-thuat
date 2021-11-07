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

Tree getMin(Tree T) 
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    return getMin(T->Left);
}

Tree getPrevious(int x, Tree T)
{

    Tree P = T, Ancestor = NULL;
    while (P != NULL)
    {
        if (P->Key == x)
        {
            if (P->Left == NULL)
                return Ancestor;
            return getMin(P->Left);
        }
        else if (P->Key < x)
        {
            Ancestor = P;
            P = P->Right;
        }
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
    x = 12;//thay doi x de duoc test case moi

    p = getPrevious(x, T);
    if (p == NULL)
        printf("%d khong co nut dung truoc", x);
    else
        printf("Nut dung truoc la %d", p->Key);
    return 0;
}
