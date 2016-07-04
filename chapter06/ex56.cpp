#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}

int main()
{
	vector<int (*)(int, int)> op{add, sub, mul, division};
	int a = 42, b = 2;
	cout << op[0](a, b) << endl
		 << op[1](a, b) << endl
		 << op[2](a, b) << endl
		 << op[3](a, b) << endl;

	return 0;
}
