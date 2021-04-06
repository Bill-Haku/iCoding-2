#include <stdio.h>
#include <stdlib.h>

int str_compare(const char* ptr1, const char* ptr2){
	int i = 0;
	int plus1 = 0, plus2 = 0;
	while(*(ptr1 + i) && *(ptr2 + i)) {
		if(*(ptr1 + i) >= 'A' && *(ptr1 + i) <= 'Z') {
			plus1 = 32;
		}
		if(*(ptr2 + i) >= 'A' && *(ptr2 + i) <= 'Z') {
			plus2 = 32;
		}
		if(*(ptr1 + i) + plus1 == *(ptr2 + i) + plus2) {
			i++;
			plus1 = 0;
			plus2 = 0;
			continue;
		}
		return (int)(*(ptr1 + i) - *(ptr2 + i));
	}
	if(!(*(ptr1 + i)) && !(*(ptr2 + i))) {
		return 0;
	}
	if(!(*(ptr1 + i))) {
		return -1;
	}
	if(!(*(ptr2 + i))) {
		return 1;
	}
	return 0;
}

int debugstr_compare(const char* ptr1, const char* ptr2){
	int i = 0;
	int plus1 = 0, plus2 = 0;
	while(*(ptr1 + i) && *(ptr2 + i)) {
		printf("%c %c\n", *(ptr1 + i), *(ptr2 + i));
		if(*(ptr1 + i) >= 'A' && *(ptr1 + i) <= 'Z') {
			printf("p1 yes\n");
			plus1 = 32;
		}
		if(*(ptr2 + i) >= 'A' && *(ptr2 + i) <= 'Z') {
			printf("p2 yes\n");
			plus2 = 32;
		}
		if(*(ptr1 + i) + plus1 == *(ptr2 + i) + plus2) {
			i++;
			plus1 = 0;
			plus2 = 0;
			printf("%d\n", i);
			continue;
		}
		printf("plus1: %d plus2: %d\n", plus1, plus2);
		printf("%d %d\n", (*(ptr1 + i) + plus1), (*(ptr2 + i) + plus2));
		return (int)(*(ptr1 + i) - *(ptr2 + i));
	}
	if(!(*(ptr1 + i))) {
		return -1;
	}
	if(!(*(ptr2 + i))) {
		return 1;
	}
	return 0;
}

int main() {
	char str1[] = "wP0E";
	char str2[] = "wp0e";
	printf("%d\n",str_compare(str1, str2));
	return 0;
}