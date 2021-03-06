#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
void visit_node(BiTNode *node);

void pre_order(BiTree root)
{
    Stack S[Stack_Size];
    BiTree T = root;
    init_stack(S); //创建一个创建一个空堆栈
    while (T || !is_empty(S)) {
        while (T) {
            visit_node(T);
            push(S, T);
            T = T->left;
        } //左边全压入栈
        pop(S, &T);
        T = T->right;
    }
}

int main() {
    return 0;
}