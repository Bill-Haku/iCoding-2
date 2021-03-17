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

void lnk_merge(LinkList A, LinkList B, LinkList C) {
	Node *pa = A->next, *pb = B->next, *pc = C;
	while(pa && pb) {
		pc->next = pa;
		pc = pc->next;
		pa = pa->next;
		pc->next = pb;
		pc = pc->next;
		pb = pb->next;
	}
	if(pa) {
		pc->next = pa;
	}
	else {
		pc->next = pb;
	}
}

/*
void lnk_merge(LinkList A, LinkList B, LinkList C) {
	int m = 0;
	int n = 0;
	int i = 1;
	Node *pre;
	Node *pre2;
	Node *preA;
	Node *preB;
	pre = A->next;
	while(pre != NULL) {
		m++;
		pre = pre->next;
	}
	pre2 = B->next;
	while(pre2 != NULL) {
		n++;
		pre2 = pre2->next;
	}

	if(m <= n) {
		C->next = A->next;
		preA = A;
		preB = B;
		pre = C;
		while(i <= m) {
			pre->next = preA->next;
			preA = preA->next;
			pre = pre->next;
			pre->next = preB->next;
			preB = preB->next;
			pre = pre->next;
			i++;
		}
		while(i > m && i <= n) {
			pre->next = preB->next;
			preB = preB->next;
			pre = pre->next;
			i++;
		}
	}

	else if(m > n) {
		C->next = A->next;
		preA = A;
		preB = B;
		pre = C;
		while(i <= n) {
			pre->next = preA->next;
			preA = preA->next;
			pre = pre->next;
			pre->next = preB->next;
			preB = preB->next;
			pre = pre->next;
			i++;
		}
		while(i > n && i <= m) {
			pre->next = preB->next;
			preB = preB->next;
			pre = pre->next;
			i++;
		}
	}
}*/