#include <stdio.h>
typedef int KeyType;
struct Node{
   KeyType       Key;
   int           Height
   struct Node  *Left, *Right;
};
typedef struct Node* AVLTree;

/*cho truoc phep toan insertNode(KeyType k, AVLTree T); */


void printLRN(AVLTree T){
    if(T!=NULL){
        printLRN(T->Left);
        printLRN(T->Right);
        printf("(%d - %d); ",T->Key,T->Height);
    }
}

int main(){
    AVLTree T = NULL;
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
    printLRN(T);

}
