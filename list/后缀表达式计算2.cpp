#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "../lib/LinkStack.h"

/*
  从键盘上输入一个后缀表达式，试编写算法计算表达式的值。
  规定：逆波兰表达式的长度不超过一行，以$符作为输入结束，
  操作数之间用空格分隔,操作符只可能有+、-、*、/四种运算。
  例如：234 34+2*$
  对应四则运算式: (234+34)*2
 */

int compute(int a, char op, int b) {
	switch (op) {
		case '+' : return (a + b);
		case '-' : return (a - b);
		case '*' : return (a * b);
		case '/' : return (a / b);
		default : return 0;
	}
}

int isNum(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	
	LinkStack *st;
	int a, b, t;
	char *str = (char*)malloc(sizeof(char)), *p;
	
	printf("Input: ", str);
	/*
	 如果用scanf的话，遇到空格会返回；
	 如果用gets的话，遇到回车才返回
	 linux 下用fgets
	 */
	//gets(str);
	fgets(str, 100, stdin);

	InitStack(st);

	for (p = str; *p != '$'; p++) {
		// 操作符, 出栈两个数计算
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/' ) {
			Pop(st, a);
			Pop(st, b);
			Push(st, compute(b, *p, a));
		}
		// 数字, 非空格
		else if (*p != ' '){
			t = 0;
			while (isNum(*p)) {
				t = t * 10 + (*p - '0');
				if (!isNum(*(p + 1))) break;
				p++;
			}
			Push(st, t);
		}
	}
	Top(st, t);
	printf("res=%d\n", t);
	return 0;
}

