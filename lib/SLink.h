#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} SLink;


// 声明
void InitList(SLink **L);
void DestroyList(SLink **L);
void Display(SLink *L);
int GetLength(SLink *L);
int Delete(SLink **L, int i);
int Insert(SLink **L, ElemType x, int i);
int GetElem(SLink *L, int i, ElemType *x);
int Locate(SLink *L, ElemType x);
void CreateLinkF(SLink **L, ElemType arr[], int n);
void CreateLinkR(SLink **L, ElemType arr[], int n);


// 头插法创建链表
void CreateLinkF(SLink **L, ElemType arr[], int n) {
	InitList(L);
	SLink *p = *L, *s
	int i;
	for (i = 0; i < n; i++) {
		s = (SLink*)malloc(sizeof(SLink));
		s->data = arr[i];
		s->next = p->next;
		p->next = s;
	}
}


// 尾插法创建链表
void CreateLinkR(SLink **L, ElemType arr[], int n) {
	InitList(L);
	SLink *p = *L, *s;
	int i;
	for (i = 0; i < n; i++) {
		s = (SLink*)malloc(sizeof(SLink));
		s->data = arr[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}


// 带头结点
void InitList(SLink **L) {
	*L = (SLink*)malloc(sizeof(SLink));
	(*L)->next = NULL;
}


void DestroyList(SLink **L) {
	SLink *pre = *L, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}


void Display(SLink *L) {
	while (L != NULL) {
		printf("%d->", L->data);
		L = L->next;
	}
	printf("null\n");
}


int GetLength(SLink *L) {
	int len = 0;
	L = L->next;
	while (L != NULL) {
		len++;
		L = L->next;
	}
	return len;
}


// 查找第i个结点的值
int GetElem(SLink *L, int i, ElemType *x) {
	int k = 0;
	if (i <= 0) return 0;
	while (L != NULL && k < i) {
		k++;
		L = L->next;
	}
	if (L == NULL) return 0;
	*x = L->data;
	return 1;
}


// 按值查找, 返回逻辑序号
int Locate(SLink *L, ElemType x) {
	int k = 0;
	while (L != NULL && L->data != x) {
		k++;
		L = L->next;
	}
	if (L == NULL) return 0;
	else return k;
}


// 在第i个位置插入结点x
int Insert(SLink **L, ElemType x, int i) {
	SLink *p = *L, *s;
	int k = 0;
	if (i <= 0) return 0;
	// 找到i位置的前一个元素
	while (p != NULL && k < i - 1) {
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;
	// insert
	s = (SLink*)malloc(sizeof(SLink));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return 1;
}


// 删除第i个结点
int Delete(SLink **L, int i) {
	SLink *p = *L, *q;
	int k = 0;
	if (i <= 0) return 0;
	// 找到要删除元素的前一个元素
	while (p != NULL && k < i - 1) {
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;
	// delete
	q = p->next;
	if (q == NULL) return 0;
	p->next = q->next;
	free(q);
	return 1;
}

