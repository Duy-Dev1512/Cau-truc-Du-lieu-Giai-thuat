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

Tree createTree(int x, Tree l, Tree r) /* Tạo một cây nhị phân từ giá trị x và hai cây con có sẵn l, r */
{
    Tree N;
    N = (struct Node *)malloc(sizeof(struct Node));
    N->Data = x;
    N->Left = l;
    N->Right = r;
    return N;
}



void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d",path[i]);
    printf("\n");
}

void printAllPaths(Tree T, int path[100], int len, int pathLen)
{
    if (T == NULL)
        return;
    if (len > pathLen)
        return;
    path[len] = T->Data;

    if (isLeaf(T) && len == pathLen)
        printArray(path, len + 1);
    printAllPaths(T->Left, path, len+1, pathLen);
    printAllPaths(T->Right, path, len+1, pathLen);
}




int main(){

    DataType path[100];
    int len=0,pathlen;\t
    Tree T,T1,T2;
    T1 = createNode(6);
    T1->Left = createNode(21);
    T1->Right = createNode(-53);
    T1->Left->Right = createNode(3);
    T1->Right->Left = createNode(-8);
    T1->Right->Right = createNode(30);
    T1->Right->Left->Left = createNode(49);
    T1->Right->Left->Right = createNode(17);
    T2=createTree(10,createTree(7,createTree(4,NULL,NULL),NULL),createTree(25,createTree(32,NULL,NULL),NULL));\t
    T=createTree(-5,T1,T2);\t
    scanf("%d",&pathlen);
    printf("Tat ca cac duong di tu nut goc den nut la co do dai %d:\n",pathlen);
    printAllPaths(T,path,len,pathlen);
    //input: 3
    return 0;
}

/*
DataType path[100];
int len=0,pathlen;
Tree T = createNode(9);
T->Left = createNode(12);
T->Right = createNode(27);
T->Left->Right = createNode(4);
T->Right->Left = createNode(56);
T->Right->Right= createNode(3);
T->Right->Right->Left = createNode(35);
T->Right->Right->Right = createNode(-15);
scanf("%d",&pathlen);
printf("Tat ca cac duong di tu nut goc den nut la co do dai %d:\n",pathlen);
printAllPaths(T,path,len,pathlen);
//input:2
*/
