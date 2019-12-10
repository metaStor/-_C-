// 字符型栈

#include "stdio.h"
#include "stdlib.h"

#define ElemType char

typedef struct Node {
	ElemType data;
	struct Node *next;
} LinkStack;


void InitStack(LinkStack **st) {
	*st = NULL;
}

int Empty(LinkStack *st) {
	if (st == NULL) return 1;
	return 0;
}

void DestroyStack(LinkStack **st) {
	LinkStack *p, *pre = *st;
	if (Empty(pre)) return;
	p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

/*
 * 坑点: c语言中不存在对变量的引用(&),
 * 除非使用双重指针, 并从main函数中传入地址
 * 再者就是将文件名改为.cpp(c++)
 */
/*
void Push(LinkStack *&st, ElemType x) {
	LinkStack *node = (LinkStack*)malloc(sizeof(LinkStack));
	node->data = x;
	node->next = st;
	st = node;
}
*/

// main: Push(&st, 100);
void Push(LinkStack **st, ElemType x) {
	LinkStack *node = (LinkStack*)malloc(sizeof(LinkStack));
	node->data = x;
	node->next = *st;
	*st = node;
}


int Pop(LinkStack **st, ElemType *x) {
	LinkStack *p;
	if (*st == NULL) return 1;
	p = *st;
	*x = p->data;
	*st = p->next;
	free(p);
	return 0;
}

int Top(LinkStack *st, ElemType *x) {
	if (Empty(st)) return 1;
	*x = st->data;
	return 0;
}

