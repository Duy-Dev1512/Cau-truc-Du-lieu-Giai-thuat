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

void makenullTree(Tree *pT)
{
    (*pT) = NULL;
}

//khởi tạo một cây 
Tree initTree()
{
    Tree T;
    return T = NULL;
}

//kiểm tra cây gốc có rỗng hay 
int isEmpty(Tree T)
{
    if (T == NULL)
        return 1;
    return 0;
}


//xác định con 
Tree leftChild(Tree n)
{
    if (n != NULL)
        return n->Left;
    else
        return NULL;
}


//xác định con phải
Tree rightChild(Tree n)
{
    if (n != NULL)
        return n->Right;
    else
        return NULL;
}

//kiểm tra nút có phải là nút lá hay 
int isLeaf(Tree n)
{
    if (!emptyTree(n))
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    else
        return 0;
}

Tree createNode(int x) /* Tạo một nút có giá trị x */
{
    struct Node *N;
    N = (struct Node *)malloc(sizeof(struct Node));
    N->Data = x;
    N->Left = NULL;
    N->Right = NULL;
    return N;
}

//duyệt tiền tự cây nhị phân
void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}


//duyệt trung tự cây nhị phân
void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Data);
        inOrder(T->Right);
    }
}

//duyệt hậu tự cây nhị phân
void postOrder(Tree T)
{
    if (T != NULL)
    {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%c ", T->Data);
    }
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

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}


//hàm tính chiều cao ccâycây
int getHeight(Tree T)
{
    if (T == NULL)
        return -1;
    else
        return 1 + Max(getHeight(T->Left), getHeight(T->Right));
}


//hàm đếm số nút lá của cây nhị phân
int getLeaves(Tree T)
{
    if (isEmpty(T))
        return 0;
    if (isLeaf(T))
        return 1;
    else
        return getLeaves(T->Left) + getLeaves(T->Right);
}

