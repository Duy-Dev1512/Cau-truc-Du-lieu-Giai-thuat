#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct {
	char ID[10];
	char Name[50];
	float R1, R2, R3;
}Student;

struct Node{
	Student Element;
	struct Node *Next;
};

typedef struct Node* List;

List getList()
{
	List L= (struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}

struct Node* locate(char ID[], List L)
{
	struct Node* p=L;		
	int Found=0;	
	while(p->Next!=NULL && !Found)
		if (strcmp(ID, p->Next->Element.ID)==0)
			Found=1;
		else p=p->Next;
	return p;
}

int append(Student s, List *pL)
{
	struct Node* p = locate(s.ID, *pL);	
			
	if (p->Next!=NULL) // Exists
		return 0;
	else
	{
		struct Node *t=(struct Node*)malloc(sizeof(struct Node));
		t->Element=s;
		t->Next = NULL;
		p->Next=t;
		return 1;
	}
}


List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList();
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		
		if (!append(s, &L))
			printf("%s exists\n",s.ID);
	}
	return L;
}
void printList(List L){
	struct Node* p=L;
	int i=1;
	while(p->Next!=NULL){
		float tong=(p->Next->Element.R1)+(p->Next->Element.R2)+ (p->Next->Element.R3);
		float tbc=tong/3.0;
		printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f",i, p->Next->Element.ID,p->Next->Element.Name,p->Next->Element.R1, p->Next->Element.R2,p->Next->Element.R3, tbc);
		i++;
		p=p->Next;
		printf("\n");
	}
	
}

List getFailedList(List L){
	struct Node* p=L;
	List pL=getList();
	while(p->Next!=NULL){
		float tong=(p->Next->Element.R1)+(p->Next->Element.R2)+ (p->Next->Element.R3);
		float tbc=tong/3.0;
		if(tbc<4.0){
			append(p->Next->Element,&pL);
		}
		p=p->Next;
	}
	return pL;
}

void showPassedList(List L){
	struct Node* p=L;
	int count=0, i=1;
	printf("\n");
	while(p->Next!=NULL){
		float tong=(p->Next->Element.R1)+(p->Next->Element.R2)+ (p->Next->Element.R3);
		float tbc=tong/3.0;
		if(tbc>=4.0){
			printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f",i, p->Next->Element.ID,p->Next->Element.Name,p->Next->Element.R1, p->Next->Element.R2,p->Next->Element.R3, tbc);
			count++;
			printf("\n");
		}
		i++;
		p=p->Next;
	}
	printf("%d students in total", count);
}

int main(){
	List L=readList();
	printList(L);       
    showPassedList(L);
    return 0;
    return 0;
}
