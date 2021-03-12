#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
#define ElemType int

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};

typedef struct _seqlist SeqList;

void del_x2y(SeqList *L, ElemType x, ElemType y) {
	/*int i,j;
	for(i=j=0;i<L->last;i++) 
		if(L->elem[i]<x || L->elem[i]>y)
			L->elem[j++] = L->elem[i];
	L->last = j;*/
	int i = 0,j = 0;
	while(i <= L->last) {
		if(i == j) {
			if(L->elem[i]<x || L->elem[i]>y) {
				i++;
				j++;
			}
			else {
				i++;
				j--;
			}
		}
		else {
			if(L->elem[i]<x || L->elem[i]>y) {
				j++;
				L->elem[j] = L->elem[i];
				i++;
			}
			else {
				i++;
			}
		}
	}
	L->last = j;
}

int main() {
	freopen("SeqList - 1.in","r",stdin);
	SeqList *L;
	ElemType x,y = 0;
	L->last = 0;
	memset(L->elem,0,sizeof(L->elem));
	int input;
	int i = 0;	
	scanf("%d%d",&x,&y);
	while(scanf("%d", &input) != EOF) {
		L->elem[i] = input;
		i++;
		L->last++;
	}
	del_x2y(L,x,y);
	for(int i=0;i<L->last;i++) {
		printf("%d ",L->elem[i]);
	}
	return 0;
}