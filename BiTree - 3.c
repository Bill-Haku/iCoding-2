#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Stack_Size 50
typedef struct Node{
    int data;
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
bool path(BiTNode* root, BiTNode* node, Stack* s);


BiTNode* nearest_ancestor(BiTree root, BiTNode* p, BiTNode* q) {
    int num1 = 0, num2 = 0;
    Stack stack1, stack2;
    BiTNode *Node1[100], *Node2[100];
    init_stack(&stack1); 
    init_stack(&stack2);
    
    path(root, p, &stack1); 
    path(root, q, &stack2);
    
    while (!is_empty(&stack1)) {
        pop(&stack1, &Node1[num1++]);
    }
    while (!is_empty(&stack2)) {
        pop(&stack2, &Node2[num2++]);
    }
        
    for (int i = 0; i < num1; ++i) { 
        for (int j = 0; j < num2; ++j) {
            if (Node1[i] == Node2[j]) {
                return Node1[i]; 
            }
        }
    }
}

int main() {
	return 0;
}