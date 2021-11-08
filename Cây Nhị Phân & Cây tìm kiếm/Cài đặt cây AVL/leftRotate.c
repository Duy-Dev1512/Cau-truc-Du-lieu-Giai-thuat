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
    if(T==NULL)return -1;
    return T->Height;
}


//ham quay don trai co truong hop cay mat can bang ben phai cua con phai
AVLTree leftRotate(AVLTree node)
{
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(temp->Left), getHeight(temp->Right)) + 1;

    return temp;
}
