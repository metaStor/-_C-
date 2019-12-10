#include "stdio.h"
#include "stdlib.h"
#include "../lib/DLink.h"


int main() {
	DLink *L;
	InitList(&L);
	/*
	for (int i = 1; i <= 5; ++i) 
		Insert(&L, i, i);
	Display(L);
	Delete(&L, 2);
	Display(L);
	 */
	int arr[5] = { 1, 2, 3, 4, 5 };
	CreateLinkR(&L, arr, 5);
	Display(L);
	DestroyList(&L);
	return 0;
}
