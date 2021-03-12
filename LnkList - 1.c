#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElemType int
#define LnkList LinkList

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;


void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
	Node *pre, *last;
	pre = L->next;
	last = L;
	int flag = 0;
	while(pre != NULL) {
		if (pre->data <= maxk) {
			flag = 1;
		}
		pre = pre->next;
		if (!flag) {
			last = last->next;
		}
		if(pre->data <= mink) {
			flag = 0;
			last->next = pre;
			break;
		}
	}
}

int main() {
	freopen("LnkList - 1.in","r",stdin);
	LnkList *L;
	*L = (LnkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	int input;
	LnkList *p;
	p = L;
	Node *r;
	int i = 0;
	int mink, maxk;
	scanf("%d%d", &mink, &maxk);	
	while(scanf("%d", &input) != EOF) {
		r = (Node*)malloc(sizeof(Node));
		r->data = input;
		p->next = r;
		p = r;
	}
	p = NULL;
	lnk_del_x2y(L,mink,maxk);
	p = L->next;
	while(p->next != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}