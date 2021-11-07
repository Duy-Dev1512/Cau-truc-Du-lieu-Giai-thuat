#include <stdio.h>
#include <stdlib.h>

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

AVLTree rightRotate(AVLTree node)
{
    AVLTree x = node->Left;
    AVLTree T2 = x->Right;
    x->Right = node;
    node->Left = T2;
    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;
    x->Height = max(getHeight(x->Left), getHeight(x->Right)) + 1;

    return x;
}

AVLTree leftRotate(AVLTree node)
{
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    return temp;
}

AVLTree rightleftRotate(AVLTree node)
{
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}

AVLTree leftrightRotate(AVLTree node)
{

    node->Left = leftRotate(node->Left);
    return rightRotate(node);
}


//ham tra ve he so can bang cua mot 
int getBalance(AVLTree T){

    if(T==NULL)
        return 0;
    return getHeight(T->Left)-getHeight(T->Right);
}


//ham chinh trong chuong trinh
AVLTree insertNode(KeyType key, AVLTree root)
{
    int balance;
    if (root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->Key = key;
        root->Height = 0;
        root->Left = NULL;
        root->Right = NULL;
    }
    else if (key < root->Key)
        root->Left = insertNode(key, root->Left);
    else if (key > root->Key)
        root->Right = insertNode(key, root->Right);
    else
        return root;

    root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));
    balance = getBalance(root);

    if (balance > 1 && key < root->Left->Key)
        return rightRotate(root);

    if (balance < -1 && key > root->Right->Key)
        return leftRotate(root);

    if (balance > 1 && key > root->Left->Key)
        return leftrightRotate(root);

    if (balance < -1 && key < root->Right->Key)
        return rightleftRotate(root);

    return root;
}

void printNLR(AVLTree T)
{
    if (T != NULL)
    {

        printf("(%d - %d); ", T->Key, T->Height);
        printNLR(T->Left);
        printNLR(T->Right);
    }
}

void printLRN(AVLTree T)
{
    if (T != NULL)
    {
        printLRN(T->Left);
        printLRN(T->Right);
        printf("(%d - %d); ", T->Key, T->Height);
    }
}


/* Tim va tra ve nut co khoa k trong cay */
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
    printNLR(T);
    printf("\n");
    printLRN(T);
    scanf("%d", &k);
    N = search(k, T);
    printf("\nHe so can bang cua nut co khoa %d la %d", k, getBalance(N));
    printf("\nChieu cao cua nut co khoa %d la %d", k, getHeight(N));
    return 0;
}
//input: cac nut tuy y trong cay
