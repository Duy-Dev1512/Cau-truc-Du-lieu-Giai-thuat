#include <stdio.h>
#include <math.h>
#define Maxlength 20
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}List;
void makenullList(List *pL)
{
	(*pL).Last=0;	
	
}
void printOddNumbers(List L){
    int i;
    for(i=0; i<L.Last;i++){
    	if(L.Elements[i]%2!=0){
    		printf("%d ", L.Elements[i]);
		}
	}
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

int emptyList(List L)
{
	return L.Last==0;
}

Position first (List L)
{
	return 1;
}

Position endList(List L){
    return L.Last+1;
}

Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

void insertList(ElementType x, Position p, List *pL)
{
	if (fullList(*pL))
		printf("Danh sach day");	
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else 
	{
	  Position q;   
	  for(q=pL->Last; q>=p; q--)
		 pL->Elements[q]=pL->Elements[q-1];	  
	  pL->Elements[p-1]=x;	  
	  pL->Last++;
	 }
}

// Ham xoa phan tu
void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(emptyList(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
	  }
	  L->Last--;
	}
}

// Tim vi tri dau tien chua x
Position locate (ElementType x, List L)
{
	Position p=first(L);
	int f=0;
	while (p!=endList(L)&& f==0)
	{
		if (retrieve (p,L)==x)
			f=1;
		else 
			p=next(p,L)	;
	}
	return p;
}
void printList(List L){
	Position P= first(L);
	while (P != endList(L)){
		printf("%d ", retrieve(P,L));
		P=next(P,L);
	}
	printf("\n");
}

void readList(List *pL){
	int i,n;
	ElementType x;
	makenullList(pL);
	scanf("%d",&n);
	for(i=1;i<=n;i++) { 
		scanf("%d",&x);
		insertList(x,endList(*pL),pL);
	}
}

int member (int x, List L){
	int i;
	for(i=0; i<L.Last;i++){
		if(L.Elements[i]==x)
			return 1;
	}
	return 0;
}
void insertSet(ElementType x, List *pL){
 		pL->Elements[pL->Last]=x;
		pL->Last++;
}
void difference(List L1,List L2,List *pL){
	makenullList(pL);
	int i;
    for(i=0;i<L1.Last;i++){
		if(member(L1.Elements[i],L2)==0)
			insertSet(L1.Elements[i],pL);
		}
}

void unionSet(List L1,List L2,List *pL){
	makenullList(pL);
	int i;
	for(i=0;i<L1.Last;i++){
		insertSet(L1.Elements[i],pL);
	}
    for(i=0;i<L2.Last;i++){
		if(member(L2.Elements[i],*pL)==0)
			insertSet(L2.Elements[i],pL);
		}
}
void normalize(List *pL){
	int p=0;
	int q;
	while(p!=pL->Last){
		q=p+1;
		while(q!=pL->Last){
			if(pL->Elements[p]==pL->Elements[q])
				deleteList(q+1,pL);
			else q++;
		}
		p++;
	}
}



void tapHop(List L1, List L2){
    int i,j;
    for(i=0; i<L1.Elements[i];i++){
    	if(member(L1.Elements[i],L2)==1)
    		printf("%d ", L1.Elements[i]);
	}
    
}
void soChan(List L){
	int i;
	for(i=0; i<L.Last;i++){
		if(L.Elements[i]%2==0){
			printf("%d ", L.Elements[i]);
		}
	}
}

float trungBinhCong(List L){
	int i;
	float tong=0;
	int count=0;
	for(i=0; i<L.Last;i++){
		if(L.Elements[i]%2==0){
			tong+=L.Elements[i];
			count++;
		}
	}
	return tong/count;
}
void erase(int x, List *pL){
	int p;
	p=locate(x,*pL);
	if(p>=1 && p<=pL->Last){
		delete(p,pL);
	}
}
int maxList(List L){
	int i,j;
	int max=0;
	for(i=0; i<L.Last; i++){
		for(j=i+1; j<L.Last;j++){
			if(L.Elements[j]>L.Elements[i])
				max=L.Elements[j];
		}
	}
	return max;
	
}
void intersection(List L1, List L2, List *pL){
	makenullList(pL);
	int i;
	for(i=0; i<L1.Last; i++){
		if(member(L1.Elements[i], L2)==1)
			insertSet(L1.Elements[i],pL);
	}
}

int main (){
	
	return 0;
}
