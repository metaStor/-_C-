#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../lib/CDLink.h"

/*
 试设计一个算法,改造一个带表头结点的双向循坏链表,
 所有结点的原有次序保持在各个结点的右链域next 中,
 并利用左链域 prior 把所有结点按照其值从小到大的顺序链接
*/


// 类似插入排序
void OrderList(CDLink **L) {
	CDLink *end = *L, *pre, *p, *s, *q = end->prior;
	s = q->prior;
	q->prior = end; // 将最右端的结点断开且与L携接循坏(建立有序区)
	while (s != end) {
		// p和pre负责遍历有序区中大于s的元素
		pre = end;
		p = pre->prior;
		// 在有序区中找插入位置
		while (p != end) {
			if (p->data > s->data) break;
			else {
				pre = p;
				p = p->prior;
			}
		}
		// 接入有序区
		q = s->prior;
		pre->prior = s;
		s->prior = p;
		// 继续往前
		s = q;
	}
}


int main() {
	CDLink *L, *p;
	int arr[5] = { 2, 1, 5, 4, 3 };
	InitList(&L);
	CreateLinkR(&L, arr, 5);
	Display(L);
	OrderList(&L);
	p = L->prior;
	while (p != L) {
		printf("%d->", p->data);
		p = p->prior;
	}
	return 0;
}
