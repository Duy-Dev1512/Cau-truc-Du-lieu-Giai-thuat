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


//ham quay don phai cho truong hop cay mat can bang ben trai cua con trai
AVLTree rightRotate(AVLTree node)
{
    AVLTree temp = node->Left;
    node->Left = temp->Right;
    temp->Right = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;
    return temp;
}


//cho truoc cac ham insertNode, printNLR, printLRN, search, getBalance, getHeight
int main()
{
    AVLTree T = NULL, N;
    int k;
    T=insertNode(50,T);
    T=insertNode(70,T);
    T=insertNode(30,T);
    T=insertNode(10,T);
    T=insertNode(20,T);
    T=insertNode(45,T);
    T=insertNode(80,T);
    T=insertNode(75,T);
    T=insertNode(100,T);
    T=insertNode(55,T);
    printNLR(T);
    printf("\n");
    printLRN(T);
    scanf("%d",&k);
    N=search(k,T);	
    printf("\nHe so can bang cua nut co khoa %d la %d",k,getBalance(N));
    printf("\nChieu cao cua nut co khoa %d la %d",k,getHeight(N));

    return 0;
}//input la key tuy y trong cay
