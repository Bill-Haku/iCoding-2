#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElemType int

struct _LinkList{
    ElemType data;
    struct _LinkList *next;
};
typedef struct _LinkList Node;
typedef struct _LinkList *LinkList;
int mink, maxk;

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
	Node *pre, *last;
	pre = L->next;
	last = L;
	int flag = 0;
	while(pre != NULL) {
		if((pre->data >= maxk || pre->data <= mink) && !flag) {
			last = pre;
			pre = pre->next;
			flag = 0;
			continue;
		}
		if(pre->data < maxk && pre->data > mink) {
			last->next = pre->next;
			free(pre);
			pre = last->next;
			flag = 1;
			continue;
		}
		if((pre->data >= maxk || pre->data <= mink) && flag) {
			last->next = pre;
			break;
		}
	}
}

void initList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void createFromTail(LinkList L) {
	Node *r;
	r = L;
	Node *s;
	int i = 0;
	int flag = 1;
	int input;
	
	while(scanf("%d", &input) != EOF) {
		s = (Node*)malloc(sizeof(Node));
		s->data = input;
		r->next = r;
		r = s;
	}
	r->next = NULL;
}

void outputList(LinkList L) {
	Node *r;
	r = L->next;
	while(r->next != NULL) {
		printf("%d ", r->data);
		r = r->next;
	}
	printf("\n");
}

int main() {
	freopen("LnkList - 1.in","r",stdin);
	LinkList *L;
	initList(L);
	scanf("%d%d", &mink, &maxk);
	createFromTail(*L);
	lnk_del_x2y(*L,mink,maxk);
	printf("%d %d\n", mink, maxk);
	//outputList(*L);
	return 0;
}