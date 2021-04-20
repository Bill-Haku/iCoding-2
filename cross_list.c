#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;


int init_cross_list(PCrossList L, const ElemType* A, int m, int n)
{
    int i, j, sum = 0;
    OLNode *p, *q;
    L->rows = m;
    L->cols = n;
    if (!(L->rowhead = (OLink*)malloc((m + 1) * (sizeof(OLink)))))
        ;
    if (!(L->colhead = (OLink*)malloc((n + 1) * (sizeof(OLink)))))
        ;
    for (i = 0; i < m; i++) {
        L->rowhead[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        L->colhead[i] = NULL;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i * n + j] != 0) {
                sum++;
                if (!(p = (OLNode*)malloc(sizeof(OLNode))))
                    ;
                p->row = i;
                p->col = j;
                p->value = A[i * n + j];
                if (L->rowhead[i] == NULL || L->rowhead[i]->col > j) {
                    p->right = L->rowhead[i];
                    L->rowhead[i] = p;
                } else {
                    for (q = L->rowhead[i]; (q->right) && (q->right->col < j); q = q->right)
                        ;
                    p->right = q->right;
                    q->right = p;
                }
                if (L->colhead[j] == NULL || L->colhead[j]->row > i) {
                    p->down = L->colhead[j];
                    L->colhead[j] = p;
                } else {
                    for (q = L->colhead[j]; (q->down) && (q->down->row < i); q = q->down)
                        ;
                    p->down = q->down;
                    q->down = p;
                }
            }
        }
    }
    L->nums = sum;
    return sum;
}

void delete_crossList(PCrossList clist, int row, int col, int k)
{
    OLNode* temp = NULL;
    OLNode* temp1 = NULL;
    OLNode* temp2 = NULL;
    
    OLNode* t = NULL;
    OLNode* t1 = NULL;
    OLNode* t2 = NULL;
    
    //删除一个结点需要修改行结点指针和列结点指针
    temp = clist->rowhead[row];
    t = clist->colhead[col];
    if (temp->value == k) {
        clist->rowhead[row] = temp->right;
    }
    if (t->value == k) {
        clist->colhead[col] = t->down;
    }
    if (t->value == k) {
        free(t);
        return;
    }
    //行遍历元素
    while (temp) {
        temp1 = temp;
        temp = temp->right;
        if (temp && temp->row == row && temp->col == col) {
            temp2 = temp;
            temp1->right = temp2->right;
            break;
        }
    }
    //列遍历元素
    while (t) {
        t1 = t;
        t = t->down;
        if (t && t->row == row && t->col == col) {
            t2 = t;
            t1->down = t2->down;
            break;
        }
    }
    free(t);
    clist->nums--;
}

int del_cross_list(PCrossList L, ElemType k)
{
    OLink pt;
    int i, j;
    int sum = 0;
    for (i = 0; i < L->rows; i++) {
        pt = L->rowhead[i];
        for (j = 0; j < L->cols; j++) {
            if (pt && pt->col == j) {
                if (pt->value == k) {
                    delete_crossList(L, i, j, k);
                    sum++;
                }
                pt = pt->right;
            }
        }
        printf("\n");
    }
    return sum;
}

int main() {
	return 0;
}