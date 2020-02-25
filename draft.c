#include "stdio.h"
#include "string.h"
#include "math.h"

void func(int*);
void func1(int*);

// 实参跟着形参变化
void func(int *t) {
	*t = 100;
	printf("func=%d\n", *t);
}

// 引用传参
void func1(int *a) {
	*a = 555;
	printf("func1=%d\n", *a);
}

void f1(int*, int);
void f2(int*, int);
void (*p[2])(int*, int);

void f1(int *p, int q) {
	int t;
	t = *p;
	*p = q;
	q = t;
}

void f2(int *p, int q) {
	int t;
	t = *p;
	*p = q;
	q = t;
}

void test_float() {
	int num, i;
	float *val, *p;
	scanf("%d", &num);
	val = (float*)malloc(sizeof(float)*num);
	for(i=0;i<num;++i) scanf("%f", &(*(val+i)));
	p = val;
	for(i=0;i<num;++i) printf("%f ", *(p+i));
	free(val);
}

void fun(int k) {
	static int a = 10;
	int b = 1;
	b++;
	printf("%d+%d+%d=%d\n", a, b, k, a+b+k);
	a+=5;
}

int main() {
	/*
	struct node { int a; int b; int c;};
	struct node s = { 3, 5, 6 };
	struct node *p = &s;
	printf("%d\n", *p);
	printf("%d\n", *(int*)p);
	*/
	int a, b;
//	func(&a);
//	func1(a);
//	printf("main=%d\n", a);
	/*
	p[0] = f1;
	p[1] = f2;
	a = 3; b = 5;
	p[0](&a, b);
	printf("%d\t%d\n", a, b);
	p[1](&a, b);
	printf("%d\t%d\n", a, b);
	*/
	//test_float();
	for (int i=1;i<=3;++i) fun(i);
	return 0;
}

