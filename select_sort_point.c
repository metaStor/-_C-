#include <stdio.h>


void selet_sort(int *data, int n);
void show(int *data, int n);


// 选择排序(指针下标)
void select_sort(int *data, int n) {
	int k, t, i, j;
	for (i = 0; i < n - 1; ++i) {
		// 找到最小元素
		for (j = i + 1, k = i; j < n; ++j) {
			k = (*(data + k) > *(data + j)) ? j : k;
		}
		if (k != i) {
			t = *(data + i);
			*(data + i) = *(data + j);
			*(data + j) = t;
		}
	}
	show(data, n);
}

// 纯指针
void select_sort1(int *data, int n) {
	int t, k, *p1, *p2;
	for (p1 = data; p1 < data + n - 1; ++p1) {
		for (p2 = p1 + 1, t = *p1; p2 < data + n; ++p2) {
			// 将有序区的最后一个元素和遍历到的最小值一直交换
			if (*p1 > *p2) {
				t = *p1, *p1 = *p2; *p2 = t;
			}
		}
	}
	show(data, n);
}

void show(int *data, int n) {
	for (int i = 0; i < n; ++i, data++) printf("%d ", *data);
}


int main() {
	int i, n, *p;
	printf("Input Numbers: ");
	scanf("%d", &n);
	int data[n];
	p = data;
	printf("Input %d Numbers: ", n);
	for (i = 0; i < n; ++i) scanf("%d", p++);
	select_sort1(data, n);
	return 0;
}

