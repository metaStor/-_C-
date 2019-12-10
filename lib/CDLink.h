#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;


typedef struct node {
	ElemType data;
	struct node *prior, *next;
} CDLink;


// 声明
void InitList(CDLink **);
void DestroyList(CDLink **);
void Display(CDLink *);
int GetLength(CDLink *);
int Delete(CDLink **, int);
int Insert(CDLink **, ElemType, int);
int GetElem(CDLink *, int, ElemType *);
int Locate(CDLink *, ElemType);
void CreateLinkF(CDLink **, ElemType [], int);
void CreateLinkR(CDLink **, ElemType [], int);


// 头插法
void CreateLinkF(CDLink **L, ElemType arr[], int n) {
	CDLink *p = *L, *s;
	for (int i = 0; i < n; i++) {
		s = (CDLink*)malloc(sizeof(CDLink));
		s->data = arr[i];
		// insert
		s->next = p->next;
		s->prior = p;
		if (p->next != *L) {
			p->next->prior = s;
		}
		p->next = s;
	}
	p->next->next = *L;
	(*L)->prior = p->next;
}


// 尾插法
void CreateLinkR(CDLink **L, ElemType arr[], int n) {
	CDLink *p = *L, *s;
	for (int i = 0; i < n; i++) {
		s = (CDLink*)malloc(sizeof(CDLink));
		s->data = arr[i];
		// insert
		s->next = p->next;
		s->prior = p;
		p->next = s;
		p = s;
	}
	p->next = *L;
	(*L)->prior = p;
}


// 带头结点
void InitList(CDLink **L) {
	*L = (CDLink*)malloc(sizeof(CDLink));
	(*L)->prior = (*L)->next = *L;
}


void DestroyList(CDLink **L) {
	CDLink *pre = *L, *p = pre->next;
	while (p != *L) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}


void Display(CDLink *L) {
	CDLink *p = L->next;
	while (p != L) {
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("loop\n");
}


int GetLength(CDLink *L) {
	CDLink *p = L->next;
	int len = 0;
	while (p != L) {
		len++;
		p = p->next;
	}
	return len;
}


int GetElem(CDLink *L, int i, ElemType *x) {
	CDLink *p = L->next;
	int k = 1;
	while (p != L && k < i) {
		k++;
		p = p->next;
	}
	if (p == L) return 0;
	*x = p->data;
	return 1;
}


int Locate(CDLink *L, ElemType x) {
	CDLink *p = L->next;
	int k = 1;
	while (p != L && p->data != x) {
		k++;
		p = p->next;
	}
	if (p == L) return 0;
	return k;
}


int Insert(CDLink **L, ElemType x, int i) {
	CDLink *pre = *L, *p = pre->next, *s;
	int k = 0;
	// 找到删除的前位置
	while (p != *L && k < i - 1) {
		k++;
		pre = p;
		p = p->next;
	}
	if (p == *L && i > k + 1) return 0;
	s = (CDLink*)malloc(sizeof(CDLink));
	s->data = x;
	// insert
	s->next = pre->next;
	s->prior = pre;
	pre->next->prior = s;
	pre->next = s;
	return 1;
}


int Delete(CDLink **L, int i) {
	CDLink *p = (*L)->next, *pre;
	int k = 1;
	if (p == *L) return 0;
	// 找到第i个位置
	while (p != *L && k < i) {
		k++;
		p = p->next;
	}
	if (p == *L) return 0;
	pre = p->prior;
	p->next->prior = pre;
	pre->next = p->next;
	free(p);
	return 1;
}

