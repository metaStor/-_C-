#include "stdio.h"


enum color { red, blue, green};
enum color1 { pink=3, yellow, white=8, black};

int main() {
	enum color c;
	enum color1 c1;
	c = green;
	c1 = yellow;
	printf("c=%d c1=%d\n", c, c1);
	return 0;
}
