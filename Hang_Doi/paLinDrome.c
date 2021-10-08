#include<stdio.h>
#include<ctype.h>
#include<string.h>


#include"AStack.h"
#include"CAQueue.h"

int isChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


int main(){
    char in[300];
    fgets(in,300,stdin);
    int len=strlen(in);
    in[len-1]='\0';
    int i;
    
    Stack Q;
    makenullStack(&Q);
    
    Queue P;
    makenullQueue(&P);
    
    for(i=0; i<len;i++){
    	if(isChar(in[i])){
    		push(tolower(in[i]),&Q);
        	enQueue(tolower(in[i]),&P);
		}
        
    }

    while(!emptyQueue(P)){
        if(top(Q) != front(P)){
        	printf("\"%s\" doc xuoi khac doc nguoc",in);
        	return 0;
		}
        pop(&Q);
        deQueue(&P);
    }
    printf("\"%s\" doc xuoi va doc nguoc nhu nhau",in);
    return 0;
}
