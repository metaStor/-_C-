#include <iostream>
#include <stack>

using namespace std;

/*
 后缀表达式这样一种类型的表达式，操作数在前，操作符在后。

 例如这样的一位数后缀表达式：

 32+5*4-$

 对等的四则表达式为：(3+2)*5-4。

 试编写程序，求解一个一位数的后缀表达式计算，表达式支持+,-,*,/操作，其中/为整除

 */

int compute(int a, char op, int b) {
	switch(op) {
		case '+' : return (a + b);
		case '-' : return (a - b);
		case '*' : return (a * b);
		case '/' : return (a / b);
		default : return 0;
	}
}

int main() {

	stack<int> s;
	string str;
	int i, a, b;

	cout<<"Input: ";
	cin>>str;

	for (i = 0; i < str.length(); ++i) {
		// 操作符, 出栈两个数计算之
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			a = s.top(); // get top
			s.pop(); // 出栈
			b = s.top();
			s.pop();
			// compute and push in
			s.push(compute(b, str[i], a));
		}
		// 数字
		else {
			s.push(str[i] - '0');
		}
	}
	cout<<s.top()<<endl;
	return 0;
}
