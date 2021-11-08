#include <stdio.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

//ham tim va tra ve mot nut co khoa key trong cay AVL
AVLTree search(KeyType key, AVLTree root)
{
    if (root == NULL)
        return NULL;

    else if (root->Key == key)
        return root;
    else if (root->Key < key)
        return search(key, root->Right);
    else
        return search(key, root->Left);
}

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
    N=search(k,T);\t
    printf("\nHe so can bang cua nut co khoa %d la %d",k,getBalance(N));
    printf("\nChieu cao cua nut co khoa %d la %d",k,getHeight(N));
    return 0;
}
