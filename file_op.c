#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 r 只读，文件必须存在

 r+ 可读写，文件必须存在

 rb+ 二进制文件 同 r+

 w 只写 文件存在则删除其内容，不存在则创建文件

 w+ 读写 文件存在则删除其内容，不存在则创建文件

 a  追加仅可写  文件存在，在末尾附加内容，不存在则建立文件

 a+ 追加读写   文件存在，在末尾附加内容，不存在则建立文件

 */

void open(FILE *&fp, char *file) {
	if ((fp = fopen(file, "a+")) == NULL) {
		printf("File can not be opend!\n");
	} else {
		printf("File opend for writing\n");
	}
}

/*
FILE* open(FILE *fp, char *file) {
	if ((fp = fopen(file, "a+")) == NULL) {
		printf("File can not be opend!\n");
		return NULL;
	} else {
		printf("File opend for writing\n");
		return fp;
	}
}
*/

void close(FILE *fp) {
	if (fclose(fp) != 0){
		printf("File can not be closed!\n");
	} else {
		printf("File is now closed\n");
	}
}

void closeAll(FILE *fp) {
	int n = fcloseall(); // 关闭所有文件, n为关闭文件个数
	printf("Colsed %d files\n", n);
}

int checkEOF(FILE *fp) {
	if (feof(fp) != 0) { // 判断文件是否结束
		printf("File is Closed!\n");
		return 1;
	} else {
		printf("File is Opening!\n");
		return 0;
	}
}

int check(FILE *fp) {
	if (ferror(fp) != 0) { // 判断文件是否出错
		printf("File is Failed!\n");
		return 1;
	} else {
		printf("File is Normal!\n");
		return 0;
	}
}

void input_char(FILE *&fp) {
	char ch;
	printf("Input char: ");
	// 从stdin标准输入
	while ((ch = fgetc(stdin)) != '\n') {
		fputc(ch, fp);
		printf("Writed %d\n", &ch);
	}
}

void read_char(FILE *&fp) {
	char ch;
	// 从stdout标准输出到screen
	while ((ch = fgetc(fp)) != EOF) {
		fputc(ch, stdout);
	}
}

void read_str(FILE *&fp) {
	char *buffer;
	buffer = (char*)malloc(sizeof(char) * 16);
	while (!feof(fp)) {
		if (fgets(buffer, 64, fp) != NULL) {
			printf("%s", buffer);
		}
	}
}

void input_str(FILE *&fp) {
	char *buffer;
	buffer = (char*)malloc(sizeof(char) * 16);
	// 从标准输入获取非空字符串
	while (strlen(fgets(buffer, 64, stdin)) > 1) {
		fputs(buffer, fp); // 输入中带有空格
		//fputs("\n", fp);
	}
}

int main() {
	FILE *fp;
	
	open(fp, "file.txt");
	input_str(fp);
	close(fp);
	
	open(fp, "file.txt");
	printf("reading!\n");
	read_str(fp);
	close(fp);
	return 0;
}

