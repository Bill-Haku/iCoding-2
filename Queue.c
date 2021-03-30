#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ElemType int

typedef struct _QueueNode {
    ElemType data;          /*数据域*/
    struct _QueueNode *next;      /*指针域*/
}LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue *LQ)
{
	LQ = NULL;
	return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
	/*LinkQueueNode *temp;
	temp = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	temp->data = x;
	if(temp != NULL) {
		temp->next = NULL;
		LQ = temp;
	}*/
	LinkQueueNode *p;
	p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	p->data = x;
	if (LQ == NULL) {
		LQ = &p;
		LQ->next = p;
	}
	else {
		p->next = LQ->next;
		LQ->next = p;
		LQ = p;
	}
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
	/*LinkQueueNode *q;
	if(LQ == NULL) {
		return false;
	}
	else if (LQ->next == LQ) {
		*x = LQ->data;
		free(LQ);
		LQ = NULL;
		return true;
	}
	else {
		q = LQ->next;
		*x = q->data;
		LQ->next = q->next;
		free(q);
		return true;
	}*/
}

int main() {
	return 0;
}