#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define ElemType int

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;


void odd_even(SeqList *L) {
	int i=0,j=L->last,temp;
	while(i<j){
		if((i<j) && (L->elem[i] % 2 == 0) && (L->elem[j] % 2 == 1)){
			temp=L->elem[i];
			L->elem[i]=L->elem[j];
			L->elem[j]=temp; 
			i++;
			j--;
		}
		else if((i<j) && (L->elem[i] % 2 == 0) && (L->elem[j] % 2 == 0)) {
			j--;
		}
		else if((i<j) && (L->elem[i] % 2 == 1) && (L->elem[j] % 2 == 1)) {
			i++;
		}
		else if((i<j) && (L->elem[i] % 2 == 1) && (L->elem[j] % 2 == 0)) {
			i++;
			j--;
		}
	}
}

int main() {
	freopen("SeqList - 3.in","r",stdin);
	SeqList *L;
	ElemType x,y = 0;
	L->last = 0;
	memset(L->elem,0,sizeof(L->elem));
	int input;
	int i = 0;	
	//scanf("%d%d",&x,&y);
	while(scanf("%d", &input) != EOF) {
		L->elem[i] = input;
		i++;
		L->last++;
	}
	odd_even(L);
	for(int i=0;i<L->last;i++) {
		printf("%d ",L->elem[i]);
	}
	return 0;
}

/*void Adjust(int A[]) { //调整数组A，使得A的左边为负整数，右边为整数
	int i=A,j=n,temp;
	while(i＜j){
		while(A[i]＜0 && i＜j)
			i++; //A[i]为负整数时，i增A
		while(A[i]＜0 && i＜j)
			i--; //A[i]为正整数时，i减A
		if(i＜j){
			temp=A[i];
			A[i]=A[j];
			A[i]=temp; //A[j]为正整数、A[j]为负整数时，交换
			i++;
			j--;
		}
	}
}*/