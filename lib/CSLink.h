#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} CSLink;


// 声明
void InitList(CSLink **);
void DestroyList(CSLink **);
void Display(CSLink *);
int GetLength(CSLink *);
int Delete(CSLink **, int);
int Insert(CSLink **, ElemType, int);
int GetElem(CSLink *, int, ElemType *);
int Locate(CSLink *, ElemType);
void CreateLinkF(CSLink **, ElemType [], int);
void CreateLinkR(CSLink **, ElemType [], int);


// 头插法创建链表
void CreateLinkF(CSLink **L, ElemType arr[], int n) {
	InitList(L);
	CSLink *p = *L, *s;
	int i;
	for (i = 0; i < n; i++) {
		s = (CSLink*)malloc(sizeof(CSLink));
		s->data = arr[i];
		s->next = p->next;
		p->next = s;
	}
}


// 尾插法创建链表
void CreateLinkR(CSLink **L, ElemType arr[], int n) {
	InitList(L);
	CSLink *p = *L, *s;
	int i;
	for (i = 0; i < n; i++) {
		s = (CSLink*)malloc(sizeof(CSLink));
		s->data = arr[i];
		p->next = s;
		p = s;
	}
	p->next = *L;
}


// 带头结点
void InitList(CSLink **L) {
	*L = (CSLink*)malloc(sizeof(CSLink));
	(*L)->next = *L;
}


void DestroyList(CSLink **L) {
	CSLink *pre = *L, *p = pre->next;
	while (p != *L) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}


void Display(CSLink *L) {
	CSLink *p = L->next;
	printf("%d->", L->data);
	while (p != L) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d\n", L->data);
}


int GetLength(CSLink *L) {
	CSLink *p = L->next;
	int len = 0;
	while (p != L) {
		len++;
		p = p->next;
	}
	return len;
}


// 查找第i个结点的值
int GetElem(CSLink *L, int i, ElemType *x) {
	CSLink *p = L->next;
	int k = 1;
	if (i <= 0) return 0;
	while (p != L && k < i) {
		k++;
		p = p->next;
	}
	if (p == L) return 0;
	*x = p->data;
	return 1;
}


// 按值查找, 返回逻辑序号
int Locate(CSLink *L, ElemType x) {
	int k = 0;
	CSLink *p = L;
	while (L != p && p->data != x) {
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;
	return k;
}


// 在第i个位置插入结点x
int Insert(CSLink **L, ElemType x, int i) {
	CSLink *pre = *L, *p = pre->next, *s;
	int k = 0;
	if (i <= 0) return 0;
	// 找到i位置的前一个元素
	while (p != *L && k < i - 1) {
		k++;
		pre = p;
		p = p->next;
	}
	if (p == *L && i > k + 1) return 0;
	// insert
	s = (CSLink*)malloc(sizeof(CSLink));
	s->data = x;
	s->next = pre->next;
	pre->next = s;
	return 1;
}


// 删除第i个结点
int Delete(CSLink **L, int i) {
	CSLink *p = *L, *q;
	int k = 0;
	if (i <= 0) return 0;
	// 找到要删除元素的前一个元素
	while (p->next != *L && k < i - 1) {
		k++;
		p = p->next;
	}
	if (p->next == *L) return 0;
	// delete
	q = p->next;
	if (q == *L) return 0;
	p->next = q->next;
	free(q);
	return 1;
}

