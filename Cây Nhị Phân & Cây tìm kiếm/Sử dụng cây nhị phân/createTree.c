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

//phép duyệt hậu tự
void postOrder(Tree T)
{
    if (T != NULL)
    {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%c ", T->Data);
    }
}

//tìm chỉ mục của một ký tự  x trong chuỗi biểu thức trung tự in bắt đầu từ vị trí star đến vị trí end
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
 
       else
             i++;
   }
   return i;
}


//tạo một node mới chứa biến dữ liệu data
struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->Data = data;
    node->Left = NULL;
    node->Right = NULL;

    return (node);
}

//tạo một cây nhị phân từ các biểu thức duyệt tiền tự và truntự
struct Node *createTree(char pre[], char inO[], int start, int end)
{

    static int index = 0;
    if (start > end)
        return NULL;

    struct Node *crNode = newNode(pre[index++]);
    if (start == end)
    {
        return crNode;
    }

    int inOrderindex = findIndex(crNode->Data, inO, start, end);

    crNode->Left = createTree(pre, inO, start, inOrderindex - 1);
    crNode->Right = createTree(pre, inO, inOrderindex + 1, end);

    return crNode;
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
  return 0;
}
/*input :ABDECF
         DBEAFC*/
