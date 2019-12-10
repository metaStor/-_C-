#include "stdio.h"
#include "../lib/SLink.h"
#include "stdlib.h"


int main() {
	SLink *L;
	ElemType arr[5] = { 1, 2, 3, 4, 5 };
	/*
	InitList(&L);
	for (int i = 1; i <= 5; ++i) {
		Insert(&L, i, i);
	}
	printf("len=%d\n", GetLength(L));
	Display(L)
	Delete(&L, 5);
	Display(L);
	DestroyList(&L);
	 */
	CreateLinkR(&L, arr, 5);
	Display(L);
	return 0;
}
