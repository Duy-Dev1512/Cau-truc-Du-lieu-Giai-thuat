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


//hàm liệt kê(in) các giá trị khóa trên đường đi của việc tìm kiếm một khóa x trong cây tìm kiếm nhị phân
void printPath(int x, Tree T)
{
    if (T == NULL)
        printf("-> Khong thay");
    else if(T->Key==x)
        printf("%d -> Tim thay", T->Key);
    else if(T->Key>x){
        printf("%d ",T->Key);
        printPath(x,T->Left);
    }
    else{
        printf("%d ", T->Key);
        printPath(x,T->Right);
    }
}

int main()
{
    Tree T = NULL;
    int x;
    insertNode(27, &T);
    insertNode(12, &T);
    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);
    x = 12;//thay đổi x để được test case mới
    printPath(x, T);
    return 0;
}
