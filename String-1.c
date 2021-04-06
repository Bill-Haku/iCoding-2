#include <stdio.h>
#include <stdlib.h>

int str_compare(const char* ptr1, const char* ptr2){
	int i = 0;
	while(*(ptr1 + i) || *(ptr2 + i)) {
		int plus1 = 0, plus2 = 0;
		if(!(*(ptr1 + i))) {
			return -1;
		}
		if(!(*(ptr2 + i))) {
			return 1;
		}
		if(*(ptr1 + i) >= 65 && *(ptr1 + i) <= 90) {
			plus1 = 32;
		}
		if(*(ptr2 + i) >= 65 && *(ptr2 + i) <= 90) {
			plus2 = 32;
		}
		if(*(ptr1 + i + plus1) == *(ptr2 + i + plus2)) {
			i++;
			continue;
		}
		return (int)(*(ptr1 + i) - *(ptr2 + i));
	}
	return 0;
}

int main() {
	return 0;
}