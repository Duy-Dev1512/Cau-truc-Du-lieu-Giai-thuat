#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;


/*tìm giá trị lớn nhất giữa 2 phần tử*/
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}


/* Tim chieu cao cua mot nut */
int getHeight(AVLTree T)
{
    if (T == NULL)
        return -1;
    return T->Height;
}

/* Quay don qua phai cho truong hop mat can bang ben trai cua con trai */
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


/* Quay don qua trai cho truong hop mat can bang ben phai cua con phai */
AVLTree leftRotate(AVLTree node)
{
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    return temp;
}


/* Quay kep phai, trai cho truong hop mat can bang ben trai cua con phai */
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

int getBalance(AVLTree T){

    if(T==NULL)
        return 0;
    return getHeight(T->Left)-getHeight(T->Right);
}


/*hàm thêm một nút có khóa key vào cây*/
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


/*liệt kê (Key, Height) theo phép duyệt tiền tự*/
void printNLR(AVLTree T)
{
    if (T != NULL)
    {

        printf("(%d - %d); ", T->Key, T->Height);
        printNLR(T->Left);
        printNLR(T->Right);
    }
}


/*liệt kê (Key, Height) theo phép duyệt hậu tự*/
void printLRN(AVLTree T)
{
    if (T != NULL)
    {
        printLRN(T->Left);
        printLRN(T->Right);
        printf("(%d - %d); ", T->Key, T->Height);
    }
}


//hàm kiểm tra một cây có phải cây AVl không
AVLTree isAVL(AVLTree T)
{
    if (getBalance(T) >= -1 && getBalance(T) <= 1)
        return T;
    return NULL;
}

int main()
{
    AVLTree T = NULL;
    T = insertNode(50, T);
    T = insertNode(30, T);
    T = insertNode(75, T);
    T = insertNode(20, T);
    T = insertNode(45, T);
    T = insertNode(70, T);
    T = insertNode(80, T);
    T = insertNode(10, T);
    T = insertNode(55, T);
    T = insertNode(100, T);
    printNLR(T);
    printf("\n");
    printLRN(T);
    if (isAVL(T))
        printf("\nCay T la cay AVL");
    else
        printf("\nCay T khong la cay AVL");
    return 0;
}
