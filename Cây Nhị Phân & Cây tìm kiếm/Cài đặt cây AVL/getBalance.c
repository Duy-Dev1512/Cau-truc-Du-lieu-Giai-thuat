#include <stdio.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int getHeight(AVLTree T)
{
    if (T == NULL)
        return -1;
    return T->Height;
    
}

int getBalance(AVLTree T){

    if(T==NULL)
        return 0;
    return getHeight(T->Left)-getHeight(T->Right);
}
