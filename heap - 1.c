#include <stdio.h>
#include <stdlib.h>
//#include "minbinheap.h" // 请不要删除，否则检查不通过

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

int parent(int i){
	if (i % 2 == 1) {
		return (i - 1) / 2;
	}
	else {
		return (i - 2) / 2;
	}
}

int left(int i){
	return 2 * i + 1;
}

int right(int i){
	return 2 * i + 2;
}	

void swap(MinHeapNode *x, MinHeapNode *y) {
	MinHeapNode temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap_node(MinHeapNode *x, MinHeapNode *y){
	swap(x,y);
}

int main() {
	return 0;
}