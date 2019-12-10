#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/*
   定义了结构体变量LNode
   以及结构体指针
   具体使用见main
*/
typedef struct Node {
	ElemType data;
	struct Node *next;
} LNode, *LinkList;

void InitList(LNode *&L) {
	//L = (LNode*)malloc(sizeof(LNode));
	L = (LinkList)malloc(sizeof(LNode));
}

int main(){
	LNode List = {666, (LNode*)malloc(sizeof(LNode))};
	LinkList L;
	InitList(L);
	L->data = 100;
	L->next = NULL;
	printf("%d\n", L->data);
//	printf("%d\n", List.data);
	return 0;
}
