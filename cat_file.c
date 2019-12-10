#include "stdio.h"
#include "stdlib.h"

/*
  查看指定文件的全部内容, 参数为文件路径
 */

int main(int argc, char *argv[]) {
	FILE *fp;
	char *buffer;
	//char buffer[128];
	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("File fail to open\n");
		exit(1);
	}
	printf("Opened %s\n", argv[1]);
	buffer = (char*)malloc(128);
	while (fgets(buffer, 128, fp) != NULL) {
		printf("%s", buffer);
	}
	free(buffer);
	if (!fclose(fp)) printf("File is now closed\n");
	return 0;
}
