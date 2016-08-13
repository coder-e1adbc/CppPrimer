#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <typeinfo>

#include <vector>
using std::vector;

int main()
{
	int arr[10];
	double d = 3.14;
	double *p = &d;
	double &r = d;

	cout << typeid(42).name() << endl
		 << typeid(arr).name() << endl
		 << typeid(string).name() << endl
		 << typeid(vector<string>).name() << endl
		 << typeid(p).name() << endl
		 << typeid(r).name() << endl;

	return 0;
}
