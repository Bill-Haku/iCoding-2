#include <stdio.h>
#include <stdlib.h>
//#include "minbinheap.h"

typedef struct _otherInfo
{
    int i;
    int j;
}OtherInfo;

typedef struct _minHeapNode
{
    int value;
    OtherInfo otherInfo;
}MinHeapNode, *PMinHeapNode;

typedef struct _minPQ {
    PMinHeapNode heap_array; // 指向堆元素数组
    int heap_size; // 当前堆中的元素个数
    int capacity;  //堆数组的大小
}MinHeap, *PMinHeap;


void init_min_heap(PMinHeap pq, int capacity){
	pq->heap_array = (MinHeapNode *)malloc(sizeof(MinHeapNode) * capacity);
	pq->heap_size = 0;
	pq->capacity = capacity;
}

int main() {
	return 0;
}