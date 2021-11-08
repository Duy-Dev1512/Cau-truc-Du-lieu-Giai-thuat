#include <stdio.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;


void printLeaves(AVLTree root){
    if(root!=NULL){
        if(root->Left==NULL && root->Right==NULL)
            printf("%d ", root->Key);
        printLeaves(root->Left);
        printLeaves(root->Right);
    }
}
