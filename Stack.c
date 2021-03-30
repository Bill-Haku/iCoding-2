#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Stack_Size 50
#define ElemType int
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);

bool push(Stack* S, ElemType x) {
	S->elem[S->top + 1] = x;
	S->top++;
	return true;
}

bool pop(Stack* S, ElemType *x) {
	*x = S->elem[S->top];
	S->top--;
	return true;
}

void init_stack(Stack *S){
    S->top = -1;
}

int compute_reverse_polish_notation(char *str) {
	Stack myStack;
	init_stack(&myStack);
	int i = 0;
	int x,y,ans = 0;
	int num = 0, flag = 0;
	while(i < strlen(str)) {
		if ((*(str + i)) >= 48 && (*(str + i)) <= 57 && !flag) {
			flag = 0;
			num = num * 10 + *(str + i) - '0';
		}
		else if(*(str + i) == ' ') {
			if (!flag) {
				push(&myStack, num);
				num = 0;
			}
			else {
				flag = 0;
			}
		}
		else if(((*(str + i)) == '+') || ((*(str + i)) == '-') || ((*(str + i)) == '*') || ((*(str + i)) == '/') || ((*(str + i)) == '%')){
			flag = 1;
			pop(&myStack, &y);
			pop(&myStack, &x);
			switch(*(str + i)) {
				case '+':
					ans = x + y;
					push(&myStack, ans);
					break;
				case '-':
					ans = x - y;
					push(&myStack, ans);
					break;
				case '*':
					ans = x * y;
					push(&myStack, ans);
					break;
				case '/':
					ans = x / y;
					push(&myStack, ans);
					break;
				case '%':
					ans = x % y;
					push(&myStack, ans);
					break;
				}
		}
		else {
			break;
		}
		i++;
	}
	if (myStack.top == 0) {
		return myStack.elem[0];
	}
	else {
		return 0;
	}
}

int main() {
	char str[] = "9 6 5 + 2 * + 7 -";
	printf("%d", compute_reverse_polish_notation(str));
	return 0;
}