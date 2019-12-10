#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
	int t;
	t = *a, *a = *b, *b = t;
}


// 形参不变
void swap_1(int *a, int *b) {
	int *t;
	t = a, a = b, b = t;
}


// 指针函数
int* min(int *a, int *b) {
	int *p;
	p = (*a < *b) ? a : b;
	return p;
}

int* min_1(int *a, int *b) {
	if (*a < *b) return a;
	return b;
}


// 函数指针
int max(int a[], int n) {
	int i, res = a[0];
	for(i = 1; i < n; ++i) 
		if (a[i] > res) res = a[i];
	return res;
}


// 指针 数组
void arr_point() {
	int a[] = {1, 2, 3, 4, 5}, *p;
	p = a;
	//p = &a[0];
	printf("a[2]:%d\n", *(p+2));
	for(; p < a + 5; ++p)
		printf("%d\n", *p);
}

// 指针 二维数组
void arr_point_2() {
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}}, *p, i, j;
	p = a[0];
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 2; ++j) {
			// 指针法
			printf("%d ", *(p++));
			printf("%d ", *(*(a+i)+j));
			// 行下标+指针
			printf("%d ", *(a[i]+j));
			// 列下标+指针
			printf("%d ", (*(a+i))[j]);
		}
		putchar('\n');
	}
}


int main(){
	int a, b, *p;
	//scanf("%d %d", &a, &b);
	// 交换值
	//swap_1(&a, &b);
	//swap(&a, &b);
	// 指针函数
	//p = min(&a, &b);
	//p = min_1(&a, &b);
	//printf("%d %d\n", a, b);
	//printf("%d\n", *p);
	
	/*
	// 定义指向函数的指针
	int (*fp)();
	int arr[] = {1, 2, 3, 4, 5};
	fp = max;
	//a = max(arr, 5);
	printf("%d\n", (*fp)(arr, 5));
	*/

	arr_point_2();
	return 0;
}
