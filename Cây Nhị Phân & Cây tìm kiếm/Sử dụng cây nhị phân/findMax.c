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


int findMax(struct Node* T)
{
    if (T == NULL)
        return -100;

    int max = T->Data;
    int leftMax = findMax(T->Left);
    int rightMax = findMax(T->Right);

    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    return max;
}

int main(){
  Tree T;
  char pre[100], in[100];
  fgets(pre,100,stdin);
  if(pre[strlen(pre)-1]=='\n'){
      pre[strlen(pre)-1]='\0';
  }
  fgets(in,100,stdin);
  if(in[strlen(in)-1]=='\n'){
      in[strlen(in)-1]='\0';
  }
  T=createTree(pre,in,0,strlen(in)-1);
  printf("Ket qua duyet hau tu: ");
  if (T!=NULL)
      postOrder(T);
  printf("\nGia tri lon nhat trong cay nhi phan la: %c",findMax(T));
  return 0;
}
/*input:ABDECF
        DBEAFC
        
        hoặc:
        ABDHIEJCFKLGM
        HDIBJEAKFLCGM*/
