#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node* Position;
typedef Position List;

//Position locate(ElementType x, List L){
//	Position P;
//	int Found =0;
//	P=L;
//	while ((P->Next !=NULL) && (Found==0)){
//		if(P->Next->Element==x) Found=1;
//		else P=P->Next;
//	return P;
//	}
//} 


int member(ElementType x, List L){
	Position P;
    P = L;
    while ((P->Next != NULL) ){
        if (P->Next->Element == x) return 1;
        else P = P->Next;
    }
    return 0;
}

Position first(List L) {
	return L;
}

Position endList(List L) {
	Position P;
	P=L;
	while (P->Next!=NULL) 
	P=P->Next;
	return P;
}


void insertList(ElementType x,Position P, List *pL){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=x;
	T->Next=P->Next;
	P->Next=T;
}

void append(ElementType x, List *pL){
	Position P = endList(*pL);
	insertList(x, P, pL);
}


void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}


void printOddNumbers(List L){
	Position P;
	List Q;
    makenullList(&Q);
	P=L;
	while(P->Next !=NULL){	
		if(abs(P->Next->Element)% 2 == 1){
		append(P->Next->Element,&Q);
		}
		P=P->Next;
		
	}
	Position O;
	O=Q;
	while(O->Next!=NULL){
		printf("%d ",O->Next->Element);
	O=O->Next;
	}
	printf("\n");
}


void copyEvenNumbers(List L1, List *pL2){
	Position P;
    makenullList(pL2);
	P=L1;
	while(P->Next !=NULL){	
		if(abs(P->Next->Element)% 2 == 0){
		append(P->Next->Element,pL2);
		}
	P=P->Next;
		
	}
//	Position O;
//	O=Q;
//	while(O->Next!=NULL){
//		printf("%d ",O->Next->Element);
//	O=O->Next;
//	}
}

void deleteList(Position P, List *pL){
    Position Temp;
    if (P->Next!=NULL){
    Temp=P->Next;
    P->Next=Temp->Next;
    free(Temp);
    }
}

List intersection(List L1, List L2){
	List pL;
	makenullList(&pL);
	Position P=L1;
	while(P->Next!=NULL){
		if(member(P->Next->Element,L2)==1)
			append(P->Next->Element,&pL);
		P=P->Next;
	}
	return pL;
}





//List readSet(){
//	List P;
//	makenullList(&P);
//	int n;
//	scanf("%d", &n);
//	int i, x;
//	for(i=1; i<=n;i++){
//		scanf("%d", &x);
//		if(member(x,P)==0){
//			addFirst(x,&P);
//		}
//	}
//	return P;
//}


//void print(List *pL){
//	Position P=(*pL);
//	while(P->Next!=NULL){
//		printf("%d ", P->Next->Element);
//	P=P->Next;
//	}
//	printf("\n");
//}

List subtract(List L1, List L2){
	Position P=L1;
	List x;
	makenullList(&x);
	while(P->Next!=NULL){
		if(member(P->Next->Element,L2)==0){
			append(P->Next->Element,&x);
		}
		P=P->Next;
	}
	return x;
}
int emptyList(List L) {
	return (L->Next==NULL);
}

void deleteX(ElementType X, List *pL){
	Position P=(*pL);
	while(P->Next!=NULL){
		if(P->Next->Element==X)
			deleteList(P,pL);
		P=P->Next;
	}
}

void normalize(List *pL){
	Position P=first(*pL);
	while(P->Next!=NULL){
		Position Q=P->Next;
		while(Q->Next!=NULL){
			if(P->Next->Element==Q->Next->Element){
				deleteList(Q,pL);
			}
			else Q=Q->Next;
		}
		P=P->Next;
	}
}

List unionSet(List L1, List L2){
	List P;
	makenullList(&P);
	P=L1;
	Position T=L2;
	while(T->Next!=NULL){
		if(member(T->Next->Element,P)!=1)
			append(T->Next->Element,&P);
		T=T->Next;
	}
	return P;
}


Position next(Position P, List L){
	return P->Next;
}
void readList(List *pL){
	int n;
	scanf("%d", &n);
	List P;
	makenullList(pL);
	int i, x;
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		append(x,pL);
	}
}

Position locate(ElementType x, List L){
    Position P;
    int Found = 0;
    P = L;
    while ((P->Next != NULL) && (Found == 0))
        if (P->Next->Element == x) Found = 1;
        else P = P->Next;
    return P;
} 


void erase(ElementType X, List *pL){
	Position P=locate(X,*pL);
	if(P->Next->Element==X)
		deleteList(P,pL);
}

List difference(List L1, List L2){
	Position p;
	makenullList(&p);
	Position q=L1;
	while(q->Next!=NULL){
		if(member(q->Next->Element,L2)!=1)
			append(q->Next->Element,&p);
		q=q->Next;
	}
	return p;
}

void addFirst(ElementType x ,List *pL){
	Position P = first(*pL);
	insertList(x,P,pL);
}

void printList(List L){
    Position P;
    P = L;
    while (P->Next != NULL){
	    printf("%d ",P->Next->Element);
	    P = P->Next;
    }
    printf("\n");
}

void sort(List *pL){
	Position p=(*pL);
	Position q;
	while(p->Next!=NULL){
		q=p->Next;
		while(q->Next!=NULL){
			if(p->Next->Element>q->Next->Element){
				int Temp=p->Next->Element;
				p->Next->Element=q->Next->Element;
				q->Next->Element=Temp;
			}
			q=q->Next;
		}
		p=p->Next;
	}
} 

float getAvg(List L){
	float S=0;
	Position p=L;
	int count=0;
	if(emptyList(L)){
		return -10000.0f; 
	}
	while(p->Next!=NULL){
		S+=p->Next->Element;
		count ++;
		p=p->Next;
	}
	float tbc=S/count;
	return tbc;
}

void removeAll(ElementType x, List *pL){
	Position p=locate(x,*pL);
	while(p->Next!=NULL){
		deleteList(p,pL);
		p=locate(x,(*pL));
		while(p->Next!=NULL){
			deleteList(p,pL);
		} 
	} 
} 


int main(){
	
	return 0;
}
