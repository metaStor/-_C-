#include "stdio.h"
#include "stdlib.h"
#include "string.h"


// 将第n个字符以后的字符复制到新字符
char* slice(char *a, char *b, int n) {
	char *p = a, *q = b;
	if (n >= strlen(a)) return NULL;
	for (p += n; *p != '\0'; ++p, ++q) *q = *p;	
	*q = '\0';
	return b;
}

int main() {
	char *a = "abcdfe", *b;
	int n;
	printf("String: %s\n", a);
	scanf("%d", &n);
	b = slice(a, b, n);
	printf("%s\n", b);
	return 0;
}
