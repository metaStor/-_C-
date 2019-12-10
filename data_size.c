#include "stdio.h"


typedef union {
	long i;
	int b[5];
	char c;
} DATE;
// 大小为int[5]:20, 但是需要补够为最大字节4的整数倍=24

struct date {
	int cat;
	DATE cow;
	double dog;
} too;
// 大小为4+24+8=40

DATE max;

int main() {
	printf("int:%d\n", sizeof(int));
	printf("char:%d\n", sizeof(char));
	printf("short:%d\n", sizeof(short));
	printf("long:%d\n", sizeof(long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
	printf("int[5]:%d\n", sizeof(int[5]));
	printf("%d", sizeof(struct date) + sizeof(max));
	return 0;
}
