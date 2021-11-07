#include <stdio.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

int getHeight(AVLTree T)
{
    if (T == NULL)
        return -1;
    return T->Height;
}


//các hàm cho sẵn trong hàm main nằm trong file isAVL.c 
//ngoại trừ hàm getHeight đang viết
int main()
{
    AVLTree T = NULL, N;
    int k;
    T = insertNode(50, T);
    T = insertNode(70, T);
    T = insertNode(30, T);
    T = insertNode(10, T);
    T = insertNode(20, T);
    T = insertNode(45, T);
    T = insertNode(80, T);
    T = insertNode(75, T);
    T = insertNode(100, T);
    T = insertNode(55, T);
    printLRN(T);
    scanf("%d", &k);
    N = search(k, T);
    printf("\nChieu cao cua nut co khoa %d la %d", k, getHeight(N));
    scanf("%d", &k);
    N = search(k, T);
    printf("\nChieu cao cua nut co khoa %d la %d", k, getHeight(N));
    return 0;
}
