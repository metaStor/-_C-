#include "stdio.h"
#include "stdlib.h"
#include "../lib/CDLink.h"


int main() {
	CDLink *L;
	InitList(&L);
	for (int i = 1; i <= 5; ++i) 
		Insert(&L, i, i);
	Display(L);
	Delete(&L, 2);
	Display(L);
	/*
	int arr[5] = { 1, 2, 3, 4, 5 }, x;
	CreateLinkR(&L, arr, 5);
	Display(L);
	printf("len=%d\n", GetLength(L));
	GetElem(L, 2, &x);
	printf("get(2)=%d\n", x);
	printf("locate(3)=%d\n", Locate(L, 3));
	*/
	DestroyList(&L);
	return 0;
}
