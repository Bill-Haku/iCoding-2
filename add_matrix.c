#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100          //假设非零元个数的最大值为100
#define ElemType int

typedef struct {
    int i,j;									//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;						//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];			// 非零元三元组表
    int m, n, len;							// 矩阵的行数、列数和非零元个数
}TSMatrix;

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ){
	if(pM->m != pN->m || pM->n != pN->n) {
		return false;
	}
	if(pM->len == 0 && pN->len == 0) {
		return true;
	}

	pQ->m = pM->m;
	pQ->n = pN->n;

	int i = 0, j = 0, k = 0;
	pQ->len = 0;

	while(i < pM->len && j < pN->len) {
		if((pM->data[i].i == pN->data[j].i && pM->data[i].j < pN->data[j].j) || (pM->data[i].i < pN->data[j].i)) {
			pQ->len++;
			pQ->data[k].i = pM->data[i].i;
			pQ->data[k].j = pM->data[i].j;
			pQ->data[k].e = pM->data[i].e;
			i++;
			k++;
		}
		else if ((pM->data[i].i == pN->data[j].i && pM->data[i].j > pN->data[j].j) || (pM->data[i].i) > pN->data[j].i) {
			pQ->len++;
			pQ->data[k].i = pN->data[j].i;
			pQ->data[k].j = pN->data[j].j;
			pQ->data[k].e = pN->data[j].e;
			j++;
			k++;
		}
		else if(pM->data[i].e + pN->data[j].e) {
			pQ->len++;
			pQ->data[k].i = pN->data[j].i;
			pQ->data[k].j = pN->data[j].j;
			pQ->data[k].e = pM->data[i].e + pN->data[j].e;
			i++;
			j++;
			k++;
		}
		else {
			i++;
			j++;
		}
	}

	while(i < pM->len) {
		pQ->len++;
		pQ->data[k].i = pM->data[i].i;
		pQ->data[k].j = pM->data[i].j;
		pQ->data[k].e = pM->data[i].e;
		i++;
		k++;
	}
	while(j < pN->len) {
		pQ->len++;
		pQ->data[k].i = pN->data[j].i;
		pQ->data[k].j = pN->data[j].j;
		pQ->data[k].e = pN->data[j].e;
		j++;
		k++;
	}
	return true;
}


int main() {
	return 0;
}