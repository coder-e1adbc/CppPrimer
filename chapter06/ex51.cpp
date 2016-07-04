#include <iostream>

using std::cout;
using std::endl;

void f() {
	cout << "f() called." << endl;
}

void f(int) {
	cout << "f(int) called." << endl;
}

void f(int, int) {
	cout << "f(int, int) called." << endl;
}

void f(double, double = 3.14){
	cout << "f(double, double) called." << endl;
}

int main()
{
//	f(2.56, 42);		// error: ambiguous call
	f(42);				// f(int);
	f(42, 0);			// f(int, int);
	f(2.56, 3.14);		// f(double, double);

	return 0;
}
