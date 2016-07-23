#include <iostream>

struct numbered {
	numbered(): mysn(num++) { }

	static int num;
	int mysn;
};

int numbered::num = 0;

using std::cout;
using std::endl;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}
