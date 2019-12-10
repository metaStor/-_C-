#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;


typedef struct node {
	ElemType data;
	struct node *prior, *next;
} DLink;


// 声明
void InitList(DLink **L);
void DestroyList(DLink **L);
void Display(DLink *L);
int GetLength(DLink *L);
int Delete(DLink **L, int i);
int Insert(DLink **L, ElemType x, int i);
int GetElem(DLink *L, int i, ElemType *x);
int Locate(DLink *L, ElemType x);
void CreateLinkF(DLink **L, ElemType arr[], int n);
void CreateLinkR(DLink **L, ElemType arr[], int n);


// 头插法
void CreateLinkF(DLink **L, ElemType arr[], int n) {
	DLink *p = *L, *s;
	for (int i = 0; i < n; i++) {
		s = (DLink*)malloc(sizeof(DLink));
		s->data = arr[i];
		// insert
		s->next = p->next;
		s->prior = p;
		if (p->next != NULL) {
			p->next->prior = s;
		}
		p->next = s;
	}
}


// 尾插法
void CreateLinkR(DLink **L, ElemType arr[], int n) {
	DLink *p = *L, *s;
	for (int i = 0; i < n; i++) {
		s = (DLink*)malloc(sizeof(DLink));
		s->data = arr[i];
		// insert
		s->next = p->next;
		s->prior = p;
		p->next = s;
		p = s;
	}
}


// 带头结点
void InitList(DLink **L) {
	*L = (DLink*)malloc(sizeof(DLink));
	(*L)->prior = (*L)->next = NULL;
}


void DestroyList(DLink **L) {
	DLink *pre = *L, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}


void Display(DLink *L) {
	L = L->next;
	while (L != NULL) {
		printf("%d<->", L->data);
		L = L->next;
	}
	printf("null\n");
}


int GetLength(DLink *L) {
	int len = 0;
	while (L != NULL) {
		len++;
		L = L->next;
	}
	return len;
}


int GetElem(DLink *L, int i, ElemType *x) {
	int k = 0;
	while (L != NULL && k < i) {
		k++;
		L = L->next;
	}
	if (L == NULL) return 0;
	*x = L->data;
	return 1;
}


int Locate(DLink *L, ElemType x) {
	int k = 0;
	while (L != NULL && L->data != x) {
		k++;
		L = L->next;
	}
	if (L == NULL) return 0;
	return k;
}


int Insert(DLink **L, ElemType x, int i) {
	DLink *p = *L, *s;
	int k = 0;
	// 找到删除的前位置
	while (p != NULL && k < i - 1) {
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;
	s = (DLink*)malloc(sizeof(DLink));
	s->data = x;
	// insert
	s->next = p->next;
	s->prior = p;
	if (p->next != NULL) {
		p->next->prior = s;
	}
	p->next = s;
	return 1;
}


int Delete(DLink **L, int i) {
	DLink *p = *L, *pre;
	int k = 0;
	// 找到第i个位置
	while (p != NULL && k < i) {
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;
	pre = p->prior;
	if (p->next != NULL) {
		p->next->prior = pre;
	}
	pre->next = p->next;
	free(p);
	return 1;
}

