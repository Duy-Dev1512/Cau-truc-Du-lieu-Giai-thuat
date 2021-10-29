#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits.h>

typedef int DataType;
struct Node
{
    int Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;



//đếm số nút có đủ 2 con 
int getFullNodes(Tree T)
{
    if (T != NULL)
    {
        int a=getFullNodes(T->Left);
        int b=getFullNodes(T->Right);
        if(T->Left!=NULL && T->Right!=NULL)
            return 1+a+b;
        return a+b;
    }
    return 0;
}






int main(){
    struct Node* root = createNode(21);
    root->Left = createNode(6);
    root->Right = NULL;
    root->Left->Left = createNode(-12);
    root->Left->Right = createNode(4);
    root->Left->Left->Left = createNode(45);
    root->Left->Left->Right = createNode(3);
    root->Left->Right->Right = createNode(18);
    int fullnodes=getFullNodes(root);
    printf("So nut co 2 con la: %d", fullnodes);
    return 0;
}

/* hoặc các testcase sau:
int fullnodes;
struct Node* root = createNode(6);
root->Left = createNode(21);
root->Right = createNode(-53);
root->Left->Right = createNode(3);
root->Right->Left = createNode(-8);
root->Right->Right = createNode(30);
root->Right->Left->Left = createNode(49);
root->Right->Left->Right = createNode(17);
fullnodes=getFullNodes(root);
printf("So nut co 2 con la: %d", fullnodes);
||
struct Node* root = createNode(9);
root->Left = createNode(12);
root->Right = createNode(17);
root->Left->Left = createNode(-21);
root->Right->Right = createNode(35);
printf("So nut co 2 con la: %d", getFullNodes(root));
*/







