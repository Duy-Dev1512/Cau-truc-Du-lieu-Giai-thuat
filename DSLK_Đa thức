#include <stdio.h>



typedef struct {
    double he_so;
    int bac;
} DonThuc;

struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao(){
	DaThuc pD;
	
	return pD->Next=NULL; 
}


void chenDonThuc(DonThuc s, DaThuc *pD){
	
}

DaThuc nhapDaThuc(){
	int n;
	scanf("%d", &n);
	DaThuc D=khoitao();
	int i;
	DonThuc d;
	for(i=1; i<=n; i++){
		scanf("%lf%d", &d.he_so, &d.bac);
		chenDonThuc(d,&D);
	}
	return D;
} 

// DaThuc tinhDaoHam(DaThuc D){
// 	DaThuc kq=khoitao();
// 	Position d=D;
// 	struct Node*  
// 	while(d->Next!=NULL){
// 		DonThuc F= 
// 	} 
	
// }

DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc kq=khoitao();
	Position P=D1;
	Position Q=D2;
	while(P->Next!=NULL){
		chenDonThuc(P->Next->e,&kq);
		P=P->Next;
	}
	while(Q->Next!=NULL){
		chenDonThuc(Q->Next->e,&kq);
		Q=Q->Next;
	}
	return kq;
}

DaThuc nhanDaThuc(DaThuc D1,DaThuc D2){
    DaThuc kq=khoitao();
    Position P = D1;
    Position Q ;
    DonThuc temp ;
    while(P->Next != NULL){
    	Q = D2;
        while(Q->Next != NULL){
            temp.he_so =P->Next->e.he_so*Q->Next->e.he_so;
            temp.bac =P->Next->e.bac+Q->Next->e.bac;
            chenDonThuc(temp,&kq);
            Q=Q->Next;
        }
        P=P->Next;
    }
    return kq;
}

int main(){
	DaThuc d = khoitao();
	struct Node *p=d;
	DonThuc s1 = {6.2, 4};
	DonThuc s2 = {4.2, 0};
	DonThuc s3 = {2, 4};
	chenDonThuc(s1, &d);
	chenDonThuc(s2, &d);
	chenDonThuc(s3, &d);
	while(p->Next!=NULL)
	{
		DonThuc e = p->Next->e;
		printf("%.3fX^%d ",e.he_so,e.bac);
		p=p->Next;
	}
	return 0;
}
