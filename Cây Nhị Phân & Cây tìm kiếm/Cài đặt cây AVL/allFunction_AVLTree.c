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

//ham tra ve chieu cao cua mot nut
int getHeight(AVLTree T)
{
    if (T == NULL)
        return -1;
    return T->Height;
    
}

//ham tra ve he so can bang cua mot nut
int getBalance(AVLTree T){

    if(T==NULL)
        return 0;
    return getHeight(T->Left)-getHeight(T->Right);
}

//in ket qua duyet hau tu
void printLRN(AVLTree T){
    if(T!=NULL){
        printLRN(T->Left);
        printLRN(T->Right);
        printf("(%d - %d); ",T->Key,T->Height);
    }
}

//in ket qua duyet tien tu
void printNLR(AVLTree T){
    if(T!=NULL){
        
        printf("(%d - %d); ",T->Key,T->Height);
        printNLR(T->Left);
        printNLR(T->Right);
    }
}

//ham quay don trai cho truong hop cay mat can bang ben phai cua con phai
AVLTree leftRotate(AVLTree node)
{
    AVLTree temp = node->Right;
    node->Right = temp->Left;
    temp->Left = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(temp->Left), getHeight(temp->Right)) + 1;

    return temp;
}

/*quay don phai cho truong hop cay mat can bang ben trai cua con trai*/
AVLTree rightRotate(AVLTree node)
{
    AVLTree temp = node->Left;
    node->Left = temp->Right;
    temp->Right = node;

    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;

    temp->Height = max(getHeight(temp->Left), getHeight(temp->Right)) + 1;
    return temp;
}


/*Quay kép trái - phải cho trường hợp mất cân bằng bên phải của con trái*/
AVLTree leftrightRotate(AVLTree node)
{

    node->Left = leftRotate(node->Left);
    return rightRotate(node);
}

/*quay kep phai-trai cho truong hop cay mat can bang ben trai cua con phai*/
AVLTree rightleftRotate(AVLTree node)
{
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}

/* ham chen mot nut co khoa key vao cay
xet xem cay co can bang khong de thuc hien lai viec can bang lai cay theo cac quy tac quay don, quay kep
va cap nhat lai chieu cao cua cac nut*/
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


//ham in cac nut la cua cay
void printLeaves(AVLTree root){
    if(root!=NULL){
        if(root->Left==NULL && root->Right==NULL)
            printf("%d ", root->Key);
        printLeaves(root->Left);
        printLeaves(root->Right);
    }
}

//ham in khoa cua cac nut co cung chieu cao
void printHeight(int height, AVLTree root)
{
    if (root != NULL)
    {
        if (root->Height == height)
            printf("%d ", root->Key);
        printHeight(height, root->Left);
        printHeight(height, root->Right);
    }
}

//ham tim kiem va tra ve mot nut co khoa key
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
    
    return 0;
}
