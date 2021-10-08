#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"CAQueue.h"


int main(){
    char enC[300];
    char code[200];
    
    fgets(enC, 300, stdin);
    fflush(stdin);
    fgets(code,200,stdin);
    fflush(stdin);
    
    enC[strlen(enC)-1]='\0';
    code[strlen(code)-1]='\0';

    Queue Q;
    makenullQueue(&Q);

    int i;
    for(i=0; i<strlen(code); i++){
        enQueue(code[i]-48,&Q);
    }

    for(i=0;i<strlen(enC);i++){
        printf("%c", enC[i]+front(Q));
        enQueue(front(Q),&Q);
        deQueue(&Q);
    }
    return 0;
}
//bai 3. giai ma thi doi dong 29 thanh printf("%c", enC[i]-front(Q));
