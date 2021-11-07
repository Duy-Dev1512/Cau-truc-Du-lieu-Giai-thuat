#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{

    int Key;

    struct Node *Left, *Right;
};
typedef struct Node *Tree;

//hàm khởi tạo và trả về một cây rỗng
Tree initTree()
{
    Tree T;
    return T=NULL;
}


int main(){
    Tree T = initTree();
    if (T==NULL) {
      printf("Da khoi tao thanh cong");
    }
    else{
      printf("Loi");
    }
    return 0;
}
