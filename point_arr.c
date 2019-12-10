#include "stdio.h"
#include "string.h"
#include "stdlib.h"


typedef char* pChar;

// 指针数组
void p_arr() {
	// char *arr[] = {"hello", "world", "!"};
	pChar arr[] = {"hello", "world", "!"};
	int i, num = sizeof(arr)/sizeof(char*); // 字符串个数
	for(i = 0; i < num; ++i) printf("%s\n", *(arr+i));
}

// 数组指针
void arr_p() {
	char arr[4] = "abc";
	char (*p)[4];
	p = &arr; 
	// p相当与二维数组的行指针，现在它指向arr[4]的地址
	printf("%s\n", *(p));
	// 输出乱码, 因为下一行无元素
	printf("%s\n", *(++p));
}


// test
void test() {
	int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int *p, (*pa)[4];
	p = &(a[1][2]);
	pa = a;
	printf("A=%d\n", p-a[1]);
	printf("B=%d\n", *(p+5));
	printf("C=%d\n", (*(pa+1))[3]);
	printf("D=%d\n", **(pa+1));
	printf("E=%d\n", *(pa[1]+1));
}

int main(int argc, char *argv[]) {
	/*
	// 复制到一个新的指针数组
	char *args[argc];
	for (int i = 0; i < argc; ++i) *(args+i) = argv[i];
	// 输出所有参数, 由于采用地址法遍历, 遍历完之后argv作废
	for (; argc >= 1; argc--, argv++) {
		printf("Args: %s\n", *argv);
	}
	// 使用备份的args
	if (!strcmp("func1", *(args+1))) p_arr();
	if (!strcmp("func2", *(args+1))) arr_p();
	*/
	test();
	return 0;
}
