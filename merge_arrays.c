#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge_arrays(const int *arr, int row, int col, int* output){
	int a[row];	//记录每一列已经走了多少位
	int flag = 0;	//记录这一列是否是目前最少的
	int isfull[row];
	memset(a, 0, sizeof(a));
	memset(isfull, 0, sizeof(isfull));
	for(int cur = 0; cur <= row * col; cur++) {
		int maxtemp = 2e8;
		for(int i = 0; i <= row; i++) {
			if(arr[i * col + a[i]] <= maxtemp && !isfull[i]) {
				maxtemp = arr[i * col + a[i]];
				flag = i;
			}
		}
		output[cur] = arr[flag * col + a[flag]];
		a[flag]++;
		if(a[flag] >= col) {
			isfull[flag] = 1;
		}
	}
	
}

int main() {
	///*
	const int row = 5;
	const int col = 6;
	int arr[row * col] = {66, 69, 73, 78, 80, 82, 19, 20, 22, 26, 34, 42, 86, 96, 98, 108, 110, 111, 74, 75, 76, 79, 84, 90, 47, 51, 55, 59, 65, 72};
	//*/
	/*
	const int row = 6;
	const int col = 3;
	int arr[6][3] ={
							{52, 53, 54},
							{71, 77, 78},
							{80, 86, 94},
							{64, 72, 81},
							{18, 25, 28},
							{19, 28, 30},
						};
	*/
	/*
	const int row = 2;
	const int col = 5;
	int arr[row][col] = {{75, 77, 86, 88, 92},{36, 40, 42, 52, 57},};
	*/
	int output[row * col];
	merge_arrays(arr, row, col, output);
	for(int i = 0; i <= row * col; i++) {
		printf("%d\n", output[i]);	
	}
	return 0;
}