void printNLR(AVLTree T){
    if(T!=NULL){
        
        printf("(%d - %d); ",T->Key,T->Height);
        printNLR(T->Left);
        printNLR(T->Right);
    }
}

//Cho trước phép toán AVLTree insertNode(KeyType k, AVLTree T) thêm một nút có khóa k vào cây
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
    printNLR(T);
    return 0;
}
