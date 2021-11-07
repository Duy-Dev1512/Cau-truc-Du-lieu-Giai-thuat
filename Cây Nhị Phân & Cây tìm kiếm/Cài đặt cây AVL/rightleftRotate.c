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
    if (T == NULL)
        return -1;
    return T->Height;
}


/* Quay don qua phai cho truong hop mat can bang ben trai cua con trai */
AVLTree rightRotate(AVLTree node)
{
    AVLTree temp = node->Left;
    node->Left = temp->Right;
    temp->Right = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(temp->Left), getHeight(temp->Right)) + 1;
    return temp;
}

/* Quay don qua trai cho truong hop mat can bang ben phai cua con phai */
AVLTree leftRotate(AVLTree node)
{
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(temp->Left), getHeight(temp->Right)) + 1;

    return temp;
}

/* Quay kép phải-trái cho trường hợp mất cân bằng bên trái của con phải */
AVLTree rightleftRotate(AVLTree node)
{
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}



/*cho truoc ham:
insertNode(k,T);
printNLR(T);
printLRN(T);
search(k,T);
getBalance(N);*/
int main(){

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
}
