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
int findIndex(DataType x, char in[], int star, int end)
{
    int i = star;
    while (i <= end)
    {
        if (x == in[i])
            return i;
        else
            i++;
    }
    return i;
}


struct Node *newNode(char data) // tao va tra ve mot nut moi
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->Data = data; // truong Data mang gia tri cua tham so dau vao
    node->Left = NULL;
    node->Right = NULL;

    return (node);
}

//tạo một cây nhị phân từ các biểu thức tiền tự và hậu 
struct Node *createTree(char pre[], char inO[], int start, int end)
{

    static int index = 0; // khai bao bien toan cuc luu chi so dang xet cua chuoi tien tu
    if (start > end)
        return NULL;

    struct Node *crNode = newNode(pre[index++]);
    if (start == end)
    {
        return crNode;
    }

    int inOrderindex = findIndex(crNode->Data, inO, start, end); // tim chi so cau ki tu dang xet

    crNode->Left = createTree(pre, inO, start, inOrderindex - 1);
    crNode->Right = createTree(pre, inO, inOrderindex + 1, end);

    return crNode;
}



int main(){
    Tree T, N;
    char pre[100], in[100], x;
    fgets(pre,100,stdin);
    if(pre[strlen(pre)-1]=='\n'){
        pre[strlen(pre)-1]='\0';
    }
    fgets(in,100,stdin);
    if(in[strlen(in)-1]=='\n'){
        in[strlen(in)-1]='\0';
    }
    scanf("%c",&x);
    T=createTree(pre,in,0,strlen(in)-1);
    N=findElement(x,T);
    if(N!=NULL){
        printf("Ton tai nut co nhan %c trong cay",x);
        printf("\nKet qua duyet hau tu cua cay con co nut goc %c la: ",x);
        postOrder(N);
    }
    else
        printf("Khong ton tai nut co nhan %c trong cay",x);
    return 0;
}

/*input:  ABDECF
          DBEAFC
          B
          hoặc:
          ABDHIEJCFKLGM
          HDIBJEAKFLCGM
          C
          hoặc:
          ABDHIEJCFKLGM
          HDIBJEAKFLCGM
          Q
