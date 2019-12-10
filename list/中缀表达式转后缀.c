#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../lib/LinkStack.h"


/*
思路:

  1. 从左向右顺序读取中缀表达式
    a. 若是数字, 直接进队Q
	b. 若是操作符'(', 直接压栈
	c. 若是操作符')', 将栈里的元素依次出栈到队列Q中
	   直到第一个配对的'(', '( )'都不入队
	c. 若是操作符c, 将其与栈顶操作符比较,
	   若栈顶元素优先级大于等于c, 则出栈入队Q直到栈顶元素小于c或栈空
	   若栈顶元素优先级小于c, 则入栈c

  2. 最后依次出队Q就可以得到逆波兰表达式

 */


void convert(char *);
int isNUmber(char);
int isOp(char);
int cmpPrior(char, char);
int getPrior(char);


int isNumber(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;
}


int isOp(char c) {
	if (c == '+' || c == '-' || c == '*' 
			|| c == '/' || c == '(' || c == ')')
		return 1;
	else
		return 0;
}

int getPrior(char c) {
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '(')
		return -1;
	return 0;
}

// p为当前元素, top为栈顶元素
int cmpPrior(char p, char top) {
	if (getPrior(p) <= getPrior(top))
		return 1;
	else
		return 0;
}

void convert(char *str) {
	LinkStack *L;
	InitStack(&L);
	char res[strlen(str)], *p, x;
	int i, top = -1;
	for (p = str; *p != '\0'; ++p) {
		// 数字直接入队
		if (isNumber(*p)) {
			res[++top] = *p;
		}
		// 操作符
		else if (isOp(*p)) {
			// ( 直接入栈
			if (*p == '(') {
				Push(&L, *p);			
			}
			// 出栈知道配对到(
			else if (*p == ')') {
				while (!Empty(L)) {
					Top(L, &x);
					if (x == '(') {
						Pop(&L, &x);
						break;
					}
					Pop(&L, &x);
					res[++top] = x;
				}
			}
			// 比较p和栈顶优先级
			else {
				while (!Empty(L)) {
					Top(L, &x);
					// ( 直接入栈
					if (x == '(') {
						Push(&L, *p);			
						break;
					}
					if (cmpPrior(getPrior(*p), getPrior(x))) {
						Pop(&L, &x);
						res[++top] = x;
					}
					else {
						Push(&L, *p);
						break;
					}
				}
				// 栈空直接入栈
				if (Empty(L)) Push(&L, *p);
			}
		}
	}
	// 将剩下的栈内元素入队
	while (!Empty(L)) {
		Pop(&L, &x);
		res[++top] = x;
	}
	DestroyStack(&L);
	// 输出队列
	for (i = 0; i <= top; ++i) {
		printf("%c", res[i]);
	}
	printf("\n");
}

int main() {
	char *str = (char*)malloc(sizeof(char)), *res;
	fgets(str, 128, stdin);
	convert(str);
	return 0;
}
