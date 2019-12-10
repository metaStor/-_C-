#include <stdio.h>

/* 
高  ++ -- - sizeof !
↑	* / %
	+ -
	<< >>
	< <= > >=
	== !=
	&
	^
	|
	&&
	||
	? :
↓	= += -= *= /= %= >>= <<= &= ^= |=
低	,
*/

void p1() {
	int a = 5, b = 4, x , y;
	x = a++*a++*a++;
	printf("a=%d x=%d\n", a, x);
	y = --b*--b*--b;
	printf("b=%d y=%d", b, y);
}


void p2() {
	int a, b, c;
	a = (b = 10);  // a=b=10
	printf("a=%d b=%d\n", a, b);
	a = (b = 10) / (c = 5); // a=b/c b=0 c=5
	printf("a=%d b=%d c=%d\n", a, b, c);
}

int main(int argc, char *argv[]) {
	p1();
	return 0;
}
