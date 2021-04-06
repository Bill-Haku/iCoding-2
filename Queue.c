#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
 
typedef struct _QueueNode {
    ElemType data;
    struct _QueueNode* next;
}LinkQueueNode, * LinkQueue;
 
 
bool init_queue(LinkQueue* LQ) {
    *LQ = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (*LQ == NULL) {
    	return false;
    }    
    (*LQ)->next = (*LQ);
    return true;
}
 
bool enter_queue(LinkQueue* LQ, ElemType x) {
    LinkQueue p= (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (p == NULL) {
    	return false;
    }
    p->data = x;
    p->next = (*LQ)->next;
    (*LQ)->next = p;
    (*LQ) = p;
    return true;
}
 
bool leave_queue(LinkQueue* LQ, ElemType* x) {
    if ((*LQ)->next == (*LQ))
        return false;
    LinkQueue p = (*LQ)->next->next;
    *x = p->data;
    if ((*LQ)->next->next != (*LQ)) {
        (*LQ)->next->next = (*LQ)->next->next->next;
    }
    else {
        (*LQ) = (*LQ)->next;
        (*LQ)->next = (*LQ);
    }
    free(p);
    return true;
    
}

int main() {
	return 0;
}