#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

bool blstr_substr(BLString src, int pos, int len, BLString *sub) {
	Block *front, *rear;
	int n = 0;
	int src_len = 0;
	int i = 0;
	Block* sh = src.head;

	if(len > src.len - pos) {
		len = src.len - pos;
	}
	if (pos < 0 || pos >= src.len || len <= 0) {
		return false;
	}

	n = len / BLOCK_SIZE;
	if(len % BLOCK_SIZE) {
		n++;
	}

	for(i = 0; i < pos/BLOCK_SIZE; i++) {
		sh = sh->next;
		src_len += BLOCK_SIZE;
	}
	int src_i = pos - src_len; //pass the blocks before pos

	front = (Block*)malloc(sizeof(Block));
	(*sub).head = front;
	for(i = 0; i < n; i++) {
		rear = (Block*)malloc(sizeof(Block));
		for(int k = 0; k < BLOCK_SIZE; k++) {
			(*rear).ch[k] = sh->ch[src_i++];
			src_len++;
			if(src_i == BLOCK_SIZE) {
				sh = sh->next;
				src_i = 0;	//goto next block when this block is full
			}
			if(src_len == pos + len) {
				break;
			}
		}
		front->next = rear;
		front = rear;
	}
	rear->next = NULL;

	if(len % BLOCK_SIZE) {
		for(n = len % BLOCK_SIZE; n < BLOCK_SIZE; n++) {
			rear->ch[n] = BLS_BLANK;	//fill in the blank in the block
		}
	}

	(*sub).len = len;
	(*sub).tail = rear;
	(*sub).head = (*sub).head->next;
	front = front->next;
	return true;
}

int main() {
	return 0;
}