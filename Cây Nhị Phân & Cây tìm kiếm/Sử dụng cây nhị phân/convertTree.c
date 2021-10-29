#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits.h>

typedef int DataType;
struct Node
{
    int Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;

Tree createNode(int x) /* Tạo một nút có giá trị x */
{
    struct Node *N;
    N = (struct Node *)malloc(sizeof(struct Node));
    N->Data = x;
    N->Left = NULL;
    N->Right = NULL;
    return N;
}


void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}


struct Node *newNode(char data) // tao va tra ve mot nut moi
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->Data = data; // truong Data mang gia tri cua tham so dau vao
    node->Left = NULL;
    node->Right = NULL;

    return (node);
}

struct Node *convertTree(Tree T)
{

    if (T == NULL)
        return NULL;

    struct Node *temp = newNode(T->Data);
    temp->Right = convertTree(T->Left);
    temp->Left = convertTree(T->Right);
    return temp;
}




int main(){
    struct Node* root = createNode(21);
    root->Left = createNode(6);
    root->Right = NULL;
    root->Left->Left = createNode(-12);
    root->Left->Right = createNode(4);
    root->Left->Left->Left = createNode(45);
    root->Left->Left->Right = createNode(3);\t
    root->Left->Right->Right = createNode(18);\t
    printf("Duyet tien tu cay da cho: ");
    preOrder(root);
    Tree MT;
    MT=convertTree(root);
    printf("\nDuyet tien tu cay phan chieu: ");
    preOrder(MT);
  
    return 0;
}

/*testcase:
struct Node* root = createNode(12);
root->Left = createNode(24);
root->Right = createNode(7);
root->Left->Right = createNode(10);
root->Right->Left = createNode(32);
root->Right->Right = createNode(-8);\t
root->Right->Left->Left = createNode(5);\t
root->Right->Left->Right = createNode(48);\t
printf("Duyet hau tu cay da cho: ");
postOrder(root);
Tree MT;
MT=convertTree(root);
printf("\nDuyet hau tu cay phan chieu: ");
postOrder(MT);
*/
