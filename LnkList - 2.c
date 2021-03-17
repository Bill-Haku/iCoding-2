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

int lnk_search(LinkList L, int k, ElemType* p_ele) {
	int cnt = 0;
	Node *pre;
	pre = L;
	while(pre->next != NULL) {
		cnt++;
		pre = pre->next;
	}
	int des = cnt - k + 1;
	if(des <= 0) {
		return 0;
	}
	pre = L;
	int i = 0;
	while((pre->next != NULL) && (i < des)) {
		pre = pre->next;
		i++;
	}
	if(i == des) {
		*p_ele = pre->data;
		return 1;
	}
	else {
		return 0;
	}
}