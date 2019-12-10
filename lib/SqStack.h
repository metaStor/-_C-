#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100
#define ElemType int

typedef struct Stack {
	ElemType data[MAXSIZE];
	int top;
} SqStack;


SqStack* InitStack() {
	SqStack *st = (SqStack*)malloc(sizeof(SqStack));
	if (st == NULL) {
		printf("Allocation Space Failure!\n");
		return NULL;
	}
	st->top = -1;
	return st;
}

void DestroyStack(SqStack *st) {
	free(st);
}

int Top(SqStack *st, ElemType *x) {
	if (st->top == -1) {
		return 0;
	}
	else {
		*x = st->data[st->top];
		return 1;
	}
}

int Pop(SqStack *st, ElemType *x) {
	if (st->top == -1) {
		return 0;
	}
	else {
		*x = st->data[st->top];
		st->top--;
		return 1;
	}
}

int Push(SqStack *st, ElemType x) {
	if (st->top == MAXSIZE - 1) {
		return 0;
	}
	else {
		st->top++;
		st->data[st->top] = x;
		return 1;
	}
}

int Empty(SqStack *st) {
	if (st->top == -1) return 0;
	return 1;
}

