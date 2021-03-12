#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElemType int

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
		if (pre->data >= mink) {
			flag = 1;
		}
		pre = pre->next;
		if (!flag) {
			last = last->next;
		}
		if(pre->data >= maxk) {
			flag = 0;
			last->next = pre;
			break;
		}
	}
}

int main() {

	return 0;
}