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


//hàm trả về nút có khóa trái nhất trong cây ( nút có giá trị nhỏ nhất)
Tree getMin(Tree T)
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    return getMin(T->Left);
}


//hàm trả về nút đứng sau nút có khóa x cho trước trong phép duyệt trung tự
Tree getNext(int x, Tree T)
{
    Tree P = T, Ancestor = NULL;
    while (P != NULL)
    {
        if (P->Key == x)
        {
            if (P->Right == NULL)
                return Ancestor;
            else
                return getMin(P->Right);
        }
        else if (P->Key > x)
        {
            Ancestor = P;
            P = P->Left;
        }
        else
            P = P->Right;
    }
    return NULL;
}

int main()
{
    Tree T = NULL;
    Tree p;
    int x;

    insertNode(27, &T);
    insertNode(12, &T);
    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);
    x = 12;

    p = getNext(x, T);
    if (p == NULL)
        printf("%d khong co nut dung sau", x);
    else
        printf("Nut dung sau la %d", p->Key);
    return 0;
}
