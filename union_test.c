#include "stdio.h"

// 共用体
union data {
	int i;
	char c;
	float f;
} a;

union data var;

// -------------
union condition {
	float score[3]; // 学生3门课程的成绩
	char situation[80]; // 教师简介
};

struct person {
	char name[20];
	char kind; // 's'为学生, 't'为教师
	union condition state;
};

int main() {

	var.i = 10;
	var.c = 'a';
	var.f = 102.3; // 共用体的值是最后一个赋值对象
	printf("%f\n", var.f);

	// -----------
	struct person p;
	puts("Input name: ");
	scanf("%s", p.name);
	getchar();
	puts("Input category: ");
	scanf("%c", &p.kind);
	if (p.kind == 's') {
		puts("Input student score: ");
		for (int i = 0; i < 3; ++i)
			scanf("%f", &p.state.score[i]);
		printf("name=%s kind=%c score=%f\n", p.name, p.kind, p.state.score[0]);
	}
	else if (p.kind == 't'){
		puts("Input teacher situation: ");
		scanf("%s", p.state.situation);
		printf("name=%s kind=%c situation=%s\n", p.name, p.kind, p.state.situation);
	}
	else {
		puts("Not exist categort!");
	}
	return 0;
}
