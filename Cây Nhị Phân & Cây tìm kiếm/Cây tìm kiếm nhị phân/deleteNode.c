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

void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}


//hàm xóa và trả về giá trị của khóa trái nhất( tức là nút có khóa nhỏ nhất)
int deleteMin(Tree *pT)
{
    int k;
    if ((*pT)->Left == NULL)
    {
        k = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return k;
    }
    else
        return deleteMin(&(*pT)->Left);
}


//hàm xóa một nút có khóa x trong cây tìm kiếm nhị phânphân
void deleteNode(int x, Tree *pT)
{
    if ((*pT) != NULL)
    {
        if (x < (*pT)->Key)
            deleteNode(x, &(*pT)->Left);
        else if (x > (*pT)->Key)
            deleteNode(x, &(*pT)->Right);
        else
        {
            if ((*pT)->Left == NULL && (*pT)->Right == NULL)
                (*pT) = NULL;
            else if ((*pT)->Left == NULL)
                (*pT) = (*pT)->Right;
            else if ((*pT)->Right == NULL)
                (*pT) = (*pT)->Left;
            else
                (*pT)->Key = deleteMin(&(*pT)->Right);
        }
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

    deleteNode(x, &T);
    inOrder(T);
    return 0;
}
