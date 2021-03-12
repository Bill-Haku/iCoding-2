#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define ElemType int

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void del_dupnum(SeqList *L)  {
	int flag = 0,val = L->elem[0];
    for(int i = 1;i<=L->last;i++){
        if(val != L->elem[i]){
            val = L->elem[i];
            flag+=1;
            L->elem[flag] = val;
        }
    }
    L->last = flag;
}

int main() {
	return 0;
}
