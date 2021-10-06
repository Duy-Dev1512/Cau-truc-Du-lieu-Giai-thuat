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
//hàm in số lẻ
void printOddNumbers(List L){
    int i;
    for(i=0; i<L.Last;i++){
    	if(L.Elements[i]%2!=0){
    		printf("%d ", L.Elements[i]);
		}
	}
}


//hàm kiểm tra danh sách đầy
int fullList(List L)
{
	return L.Last==Maxlength;
}


//hàm kiểm tra danh sách rỗng
int emptyList(List L)
{
	return L.Last==0;
}

//hàm trả về vị trí đầu trong danh sách
Position first (List L)
{
	return 1;
}


//hàm trả về vị trí cuối của danh sách
Position endList(List L){
    return L.Last+1;
}

//hàm trả về vị trí kế vị trí phần tử p
Position next(Position P, List L){
    return P+1;
}


//hàm trả về vị trí phần tử đứng trước phần tử p
Position previous(Position P, List L){
    return P-1;
}

//hàm trả về nội dung phần tử tại vị trí P
ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}


//hàm chèn 1 phần tử x vào vị trí p trong danh sách được chỉ bởi con trỏ *
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

//hàm in 1 danh sách LL
void printList(List L){
	Position P= first(L);
	while (P != endList(L)){
		printf("%d ", retrieve(P,L));
		P=next(P,L);
	}
	printf("\n");
}


//hàm đọc vào 1 danh sách
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


//hàm kiểm tra xem phần tử x có trong danh sách L hay không
int member (int x, List L){
	int i;
	for(i=0; i<L.Last;i++){
		if(L.Elements[i]==x)
			return 1;
	}
	return 0;
}


//hàm chèn một phần tử vào cuối danh sách
void insertSet(ElementType x, List *pL){
 		pL->Elements[pL->Last]=x;
		pL->Last++;
}


//hàm chèn phần tử từ danh sách L1 vào danh sách L2 nếu phần tử đó chưa xuất hiện trong danh sácL2L2 
void difference(List L1,List L2,List *pL){
	makenullList(pL);
	int i;
    for(i=0;i<L1.Last;i++){
		if(member(L1.Elements[i],L2)==0)
			insertSet(L1.Elements[i],pL);
		}
}


//hàm tìm tập hợp của 2 tập hợp
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

//hàm chuẩn hóa dsáchsách
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


//in tập hợp
void tapHop(List L1, List L2){
    int i,j;
    for(i=0; i<L1.Elements[i];i++){
    	if(member(L1.Elements[i],L2)==1)
    		printf("%d ", L1.Elements[i]);
	}
    
}

//hàm tìm số chẵn có trong thợphợp
void soChan(List L){
	int i;
	for(i=0; i<L.Last;i++){
		if(L.Elements[i]%2==0){
			printf("%d ", L.Elements[i]);
		}
	}
}


//hàm tính trung bình cộng các phần tử trong tập hợp
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

//hàm xóa phần tử đầu tiên có giá trị là x trong danh sách
void erase(int x, List *pL){
	int p;
	p=locate(x,*pL);
	if(p>=1 && p<=pL->Last){
		delete(p,pL);
	}
}

//hàm tìm giá trị lớn nhất trong tập hợp 
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

//hàm tìm tập hợp giao của 2 tập 
void intersection(List L1, List L2, List *pL){
	makenullList(pL);
	int i;
	for(i=0; i<L1.Last; i++){
		if(member(L1.Elements[i], L2)==1)
			insertSet(L1.Elements[i],pL);
	}
}

int main (){
	List L;
	readList(&L);
	printList(L);
	soChan(L);
	float a=trungBinhCong(L);
	printf("\n%.3f", a);
	return 0;
}
