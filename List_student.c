#include <stdio.h>

#define max 80

struct SinhVien{
	char MSSV[10];
	char HoTen[50];
	float DiemLT,DiemTH1,DiemTH2;
};

typedef struct{
	struct SinhVien A[40];
	int n;
}DanhSach;

int dsDay(DanhSach L){
	if(L.n==40)
		return 1;
	return 0;
}


void chenCuoi(struct SinhVien s, DanhSach *pL){
	int i;
	if(dsDay(*pL)==1){
		printf("Loi! Danh sach day!");
	}
	else{
		pL->A[pL->n]=s;
		pL->n++;
	}
}

int ktRong(DanhSach L){
	if(L.n==0)
		return 1;
	return 0;
}


DanhSach nhap(){
	
	DanhSach L=dsRong();
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("\n");
		char ms[10];
		fgets(ms, 10, stdin);
		if(ms[strlen(ms)-1]=='\n')
			ms[strlen(ms)-1]='\0';
		strcpy(L.A[i].MSSV,ms);
		scanf("\n");
		char hoten[50];
		fgets(hoten,50,stdin);
		if(hoten[strlen(hoten)-1]=='\n')
			hoten[strlen(hoten)-1]='\0';
		strcpy(L.A[i].HoTen,hoten);
		scanf("%f%f%f", &L.A[i].DiemLT, &L.A[i].DiemTH1,&L.A[i].DiemTH2);
		L.n++;
	}
	return L;
}

// DanhSach nhap(){
	
// 	DanhSach L=dsRong();
// 	int i, n;
// 	scanf("%d", &n);
// 	for(i=0; i<n; i++){
// 		struct SinhVien sv;
// 		scanf("\n");
// 		char ms[10];
// 		fgets(ms, 10, stdin);
// 			if(ms[strlen(ms)-1]=='\n')
// 			ms[strlen(ms)-1]='\0';
// 			strcpy(sv.MSSV,ms);
// 			scanf("\n");
// 			if(sv.MSSV[i]!=L.A[i].MSSV[i]){
// 				char hoten[50];
// 				fgets(hoten,50,stdin);
// 				if(hoten[strlen(hoten)-1]=='\n')
// 					hoten[strlen(hoten)-1]='\0';
// 				strcpy(sv.HoTen,hoten);
// 				scanf("%f%f%f", &sv.DiemLT, &sv.DiemTH1,&sv.DiemTH2);
// 			}
			
// 			chenCuoi(sv, &L);
// 	}
// 	return L;
// }
void hienthi (DanhSach L){
	int i;
	float tong=0;
	for(i=0;i<L.n;i++){
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV,L.A[i].HoTen,L.A[i].DiemLT,L.A[i].DiemTH1,L.A[i].DiemTH2);
	}
	
	
}
DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
}





int xoaTai(int p, DanhSach *pL){
	
	if(p<pL->n){
		pL->A[p-1]=pL->A[p];
		pL->n--;
	}
	return 0;
}

int tim(char x[10], DanhSach L){
    int p = 1;
    while (p <= L.n){
        if(strcmp(x, L.A[p-1].MSSV )== 0)
            return p;
        p++;
    }
    return L.n+1;
}

void xoaSinhVien(char x[10], DanhSach *pL){
	int p=tim(x,*pL);
	if(p>=1 && p<=pL->n){
		xoaTai(p,pL);
	}
	
}

DanhSach chepKhongDat(DanhSach L){
	DanhSach kq;
	kq=dsRong();
	int i;
	for(i=0; i<L.n; i++){
		double tong=(L.A[i].DiemLT)+(L.A[i].DiemTH1)+(L.A[i].DiemTH2);
		if(tong<4.0){
			chenCuoi(L.A[i],&kq);
		}
	}
	return kq;
}
int main(){
	DanhSach L;
	L=nhap();
	hienthi(L);
	
	return 0;
}
