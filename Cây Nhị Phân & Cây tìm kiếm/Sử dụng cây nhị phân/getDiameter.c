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


int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}


//tính chiều cao của 
int getHeight(Tree T)
{
    if (T == NULL)
        return -1;
    else
        return 1 + Max(getHeight(T->Left), getHeight(T->Right));
}


//tính đường kính của cây nhi phân
//Đường kính của một cây là số nút trên đường đi dài nhất giữa hai nút lá của cây.
void getDiameter(struct Node *T, int *diameter)
{
    if (T != NULL)
    {
        if ((*diameter) < (getHeight(T->Left) + getHeight(T->Right) + 3))
            (*diameter) = getHeight(T->Left) + getHeight(T->Right) + 3;
        getDiameter(T->Left, diameter);
        getDiameter(T->Right, diameter);
    }
}



int main(){
  int diameter=0;	
  struct Node* root = createNode('A');
  root->Left = createNode('B');
  root->Right = createNode('C');
  root->Left->Right = createNode('D');
  root->Right->Left = createNode('E');
  root->Right->Right = createNode('F');
  root->Right->Left->Left = createNode('G');
  root->Right->Left->Right = createNode('H');	
  getDiameter(root,&diameter); 
  printf("Duong kinh cua cay da cho la: %d", diameter);
  return 0;
  
  //hoặc testcase :
  int diameter=0;	
  struct Node* root = createNode('A');
  root->Left = createNode('B');
  root->Right = NULL;
  root->Left->Left = createNode('C');
  root->Left->Right = createNode('D');
  root->Left->Left->Left = createNode('E');
  root->Left->Left->Right = createNode('F');
  root->Left->Right->Right = createNode('G');
  getDiameter(root,&diameter); 
  printf("Duong kinh cua cay da cho la: %d", diameter);

}
