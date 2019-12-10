#include "stdio.h"
#include "stdlib.h"

/*
	结构体变量用 . 访问, 结构体指针变量用 ->
	
 */

struct node {
	int data;
	struct node *next;
} p, *pt;

struct student {
	char name[20];
	char sex[6];
	int age;
} s1 = { "shenhao", "man", 20 };

 // ------------------------------------
typedef int (*Fun)(void *obj, int argc, int *argv);

struct Function {
	const char *name;
	Fun call;
	unsigned char flag;
	unsigned char extra;
};

static int foo1(void *obj, int argc, int *argv) { return 0; }
static int foo2(void *obj, int argc, int *argv) { return 1; }
static int foo3(void *obj, int argc, int *argv) { return 2; }

static struct Function my_function[] = {
	{ "foo1", foo1, 0, 22 },
	{ "foo2", foo2, 1, 32 },
	{ "foo3", foo3, 2, 52 },
	{ 0 }
};

 // ------------------------------------

int main(int argc, char *argv[]) {
	pt = &p;
	p.data = 10;
	printf("p=%d\tpt=%d\n", p.data, pt->data);
	pt->data = 20;
	printf("p=%d\tpt=%d\n", p.data, pt->data);
	printf("name=%s sex=%s age=%d\n\n", s1.name, s1.sex, s1.age);
	// ---------
	printf("sizeof Function=%d\n", sizeof(struct Function));
	printf("sizeof my_function=%d\n", sizeof(my_function));
	return 0;
}

