#include <stdio.h>
#include<stdlib.h>

typedef int KeyType;
struct Node
{

    int Key;

    struct Node *Left, *Right;
};
typedef struct Node *Tree;


//ham duyet cay theo phep duyet tien tu
void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

//ham duyet cay theo phep duyet trung tu
void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}


//ham duyet cay theo phep duyet hau tu
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
        (*pT)=(struct Node*)malloc(sizeof(struct Node));
        (*pT)->Key=X;
        (*pT)->Left=NULL;
        (*pT)->Right=NULL;
    }
    else if (X < (*pT)->Key)
        insertNode(X, &((*pT)->Left));
    else if (X > (*pT)->Key)
        insertNode(X, &((*pT)->Right));
}

int main()
{
    Tree T = NULL;
    insertNode(10, &T);
    insertNode(-1, &T);
    insertNode(15, &T);
    insertNode(12, &T);
    inOrder(T);
    return 0;
}
