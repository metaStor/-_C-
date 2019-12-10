#include "stdio.h"
#include "stdlib.h"

/*
 传入两个参数, 将第一个文件内容读入, 然后反序写入另一个文件
 */

#define SIZE 5000

FILE* open(FILE *fp, char *file, char *state) {
	if ((fp = fopen(file, state)) == NULL) {
		printf("File %s can not be opend!\n", file);
		return NULL;
	} else {
		printf("File %s opend for writing\n", file);
		return fp;
	}
}

void close(FILE *fp) {
	if (fclose(fp) != 0){
		printf("File can not be closed!\n");
	} else {
		printf("File is now closed\n");
	}
}

int main(int argc, char *argv[]) {
	FILE *src, *tar;
	int i = 0;
	char *buffer = (char*)malloc(sizeof(SIZE));
	src = open(src, argv[1], "r");
	tar = open(tar, argv[2], "w");
	while (!feof(src)) {
		buffer[i++] = fgetc(src);
		if (i >= 5000) {
			printf("Stack over!\n");
			exit(1);
		}
	}
	while (--i > 0) {
		fputc(buffer[i], tar);
	}
	close(src);
	close(tar);
	printf("Processing compele!\n");
	return 0;
}
