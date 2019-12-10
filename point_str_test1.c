#include "stdio.h"
#include "string.h"
#include "stdlib.h"


/*
   输入字符串和指定字符, 将字符串中的指定字符删除
 */

// 将非目标字符接到新字符上
char* myRemove(char *str, char c) {
	char *res, *t;
	t = (char*)malloc(sizeof(char));
	res = t;
	for (; *str != '\0'; ++str) {
		if (*str != c) *t++ = *str;
	}
	*t = '\0';
	return res;
}

// str原地修改
void myRemove2(char *str, char c) {
	char *t;
	for (t = str; *t != '\0'; ++t) {
		if (*t != c) *str++ = *t;
	}
	*str = '\0';
}


int main(int argc, char *args[]) {
	char *str, c;
	str = (char*)malloc(sizeof(char));
	printf("Input String and Char Removed: ");
	scanf("%s %c", str, &c);
	printf("%s %c\n", str, c);
	//printf("Processed: %s\n", myRemove(str, c));
	myRemove2(str, c);
	printf("Processed: %s\n", str);
	return 0;
}
