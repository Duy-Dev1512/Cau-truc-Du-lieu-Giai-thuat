#include <stdio.h>
#include <string.h>

#define Maxlength 100
typedef char ElementType;
typedef struct
{
	ElementType Elements[Maxlength];
	int Top_idx;
} Stack;

void makenullStack(Stack *pS)
{
	pS->Top_idx = Maxlength;
}

int full(Stack S)
{
	return S.Top_idx == 0;
}

int emptyStack(Stack S)
{
	if (S.Top_idx == Maxlength)
		return 1;
	return 0;
}

void push(ElementType x, Stack *pS)
{
	if (full(*pS))
		printf("Loi! Ngan xep day!");
	else
	{
		pS->Top_idx = pS->Top_idx - 1;
		pS->Elements[pS->Top_idx] = x;
	}
}
ElementType top(Stack S)
{
	if (!emptyStack(S))
		return S.Elements[S.Top_idx];
	else
		printf("Loi! Ngan xep rong");
}

void pop(Stack *pS)
{
	if (!emptyStack(*pS))
		pS->Top_idx = pS->Top_idx + 1;
	else
		printf("Loi! Ngan xep rong!");
}

//void hienthi(NganXep *pS){
//	while(!ktRong(*pS)){
//		printf("%d ", giatriDinh(*pS));
//		xoa(pS);
//	}
//}

//void doiNhiPhan(ElementType n, Stack *pS){
//	makenullStack(pS);
//	while(n!=0){
//		push(n%2,pS);
//		n=n/2;
//	}
//}

void readStack(Stack *pS)
{
	int n, i;
	makenullStack(pS);
	scanf("%d", &n);
	ElementType x;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		push(x, pS);
	}
}

void printStack(Stack *pS)
{
	while (!emptyStack(*pS))
	{
		printf("%d ", top(*pS));
		pop(pS);
	}
}

int mucUutien(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
}

int ktChuoi()
{
	char kitu[100];
	int i;
	fgets(kitu, 100, stdin);
	if (kitu[strlen(kitu) - 1] == '\n')
		kitu[strlen(kitu) - 1] = '\0';
	Stack S;
	makenullStack(&S);
	for (i = 0; i < strlen(kitu); i++)
	{
		if (kitu[i] == '(')
			push(kitu[i], &S);
		if (kitu[i] == ')' && emptyStack(S) != 1)
		{
			pop(&S);
		}
	}
	if (emptyStack(S))
		return 1;
	return 0;
}
float tinhGiatri(char ST[50])
{
	int len = strlen(ST), i, x;
	Stack S;
	makenullStack(&S);
	float gt = 0, dinh, dinh2;
	for (i = 0; i < len; i++)
	{
		if (ST[i] == ' ')
			i++;
		if (ST[i] >= '0' && ST[i] <= '9')
		{
			x = ST[i] - '0';
			push(x, &S);
		}
		else
		{
			dinh = top(S);
			pop(&S);
			dinh2 = top(S);
			pop(&S);
			switch (ST[i])
			{
			case '+':
				gt = dinh2 + dinh;
				break;
			case '-':
				gt = dinh2 - dinh;
				break;
			case '/':
				gt = dinh2 / dinh;
				break;
			case '*':
				gt = dinh2 * dinh;
			}
			push(gt, &S);
		}
	}
	return gt;
}

void inThaplucphan(int n)
{
	int rem;
	int i = 1, j;
	char hex[100];
	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
			rem += 48;
		else
			rem += 55;
		hex[i++] = rem;
		n /= 16;
	}
	for (j = i - 1; j > 0; j--)
	{
		printf("%c", hex[j]);
	}
}

void chuyenHauto(char trungto[50], char hauto[50])
{
	int len = strlen(trungto);
	int i, j = 0;
	Stack S;
	makenullStack(&S);
	for (i = 0; i < len; i++)
	{
		char c=trungto[i];
		if(trungto[i]==' '){
			i++;
		}
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		{
			hauto[j] = c;
			j++;
		}
		else if (c == '(')
			push(c, &S);
		else if (c == ')')
		{
			while (top(S) != '(')
			{
				if (top(S) =='+' || top(S) =='-' || top(S) =='*' || top(S) =='/')
				{
					hauto[j] = top(S);
					j++;
					pop(&S);
				}
			}
			pop(&S);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!emptyStack(S) && top(S) != '(' && mucUutien(c) <= mucUutien(top(S)))
			{
				if (top(S) == '+' || top(S) == '-' || top(S) == '*' || top(S) == '/')
				{
					hauto[j] = top(S);
					j++;
					pop(&S);
				}
			}
			push(c, &S);
		}
		
	}
	while (!emptyStack(S))
	{
			hauto[j] = top(S);
			j++;
			pop(&S);
	}
}
