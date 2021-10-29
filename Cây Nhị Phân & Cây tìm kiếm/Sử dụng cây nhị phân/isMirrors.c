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

Tree createNode(int x) /* Tạo một nút có giá trị x */
{
    struct Node *N;
    N = (struct Node *)malloc(sizeof(struct Node));
    N->Data = x;
    N->Left = NULL;
    N->Right = NULL;
    return N;
}

void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

int isMirrors(Tree T1, Tree T2)
{
    if (T1 == NULL && T2 == NULL)
        return 1;
    else if (T1 == NULL || T2 == NULL)
        return 0;
    return (T1->Data==T2->Data && isMirrors(T1->Left,T2->Right) && isMirrors(T1->Right,T2->Left));
}



int main(){

    struct Node* T1 = createNode(9);
    T1->Left = createNode(12);
    T1->Right = createNode(17);
    T1->Left->Left = createNode(-21);   
    T1->Right->Right = createNode(35);
    struct Node* T2 = createNode(9);
    T2->Left = createNode(17);
    T2->Right = createNode(12);
    T2->Left->Left = createNode(35);   
    T2->Right->Right = createNode(-21);
    printf("Bieu thuc tien tu cua cay T1: "); 
    preOrder(T1);
    printf("\nBieu thuc tien tu cua cay T2: "); 
    preOrder(T2);
    if(isMirrors(T1,T2))    	
      printf("\nT1 va T2 phan chieu nhau");
    else
      printf("\nT1 va T2 khong phan chieu cua nhau");
    return 0;
}

/*testcase 2:
    Tree T1,T2;
    T1=createTree(21,createTree(6,createTree(-12,createTree(45,NULL,NULL),
      createTree(3,NULL,NULL)),createTree(4,NULL,createTree(8,NULL,NULL))),
      NULL);
    T2=createTree(21,createTree(6,createTree(4,createTree(-12,NULL,NULL),
      createTree(3,NULL,NULL)),createTree(8,NULL,createTree(45,NULL,NULL))),
      NULL);
    printf("Bieu thuc hau tu cua cay T1: "); 
    postOrder(T1);
    printf("\nBieu thuc hau tu cua cay T2: "); 
    postOrder(T2);
    if(isMirrors(T1,T2))
         printf("\nT1 va T2 phan chieu nhau");
    else
         printf("\nT1 va T2 khong phan chieu cua nhau");
*/
