#include <stdio.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;


//hàm in các khóa của những nút có cùng chiều cao height
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

//các hàm trong main có sẵn
int main(){

    AVLTree T = NULL;
    int height; 
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
    scanf("%d",&height);
    printf("\nCac nut co cung chieu cao %d: ",height);
    printHeight(height,T);
    scanf("%d",&height);
    printf("\nCac nut co cung chieu cao %d: ",height);
    printHeight(height,T);
  return 0;
}
// input lần lượt là 2 giá trị chiều cao 
