#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//#include "bitree.h" //请不要删除，否则检查不通过
#define Stack_Size 50
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false

/*
bool path(BiTNode* root, BiTNode* node, Stack* s){
	BiTNode* cur;
	cur = root;
	push(s, cur);
	if (cur == node) {
		return true;
	}		
	if(cur->left == NULL && cur->right == NULL) {
		pop(s, &cur);
		top(s, &cur);
		return false;
	}
	if (cur->left != NULL) {
		cur = cur->left;
		if(path(cur, node, s)) {
			return true;
		}
	}
	if(cur->right != NULL) {
		cur = cur->right;
		if(path(cur, node, s)) {
			return true;
		}
	}
	if(is_empty(s)) {
		return false;
	}
	return false;
}*/

bool path(BiTNode* root, BiTNode* node, Stack* s) {
    BiTree cur = root, p=NULL;
    if (cur == NULL || node == NULL || !is_empty(s)) {
        return false;
    }
    while (cur || !is_empty(s)) {
        while (cur) {
            push(s, cur);
            if (cur == node) {
                return true;
            }
            cur = cur->left;
        }
        top(s, &cur);
        if (!cur->right || cur->right == p) {
            p = cur;
            pop(s, &cur);
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
    return false;
}

int main() {
	return 0;
}