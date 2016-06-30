#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	cout << "bool: " << sizeof(bool) << endl
		 << "char: " << sizeof(char) << endl
		 << "short: " << sizeof(short) << endl
		 << "int: " << sizeof(int) << endl
		 << "long: " << sizeof(long) << endl
		 << "long long: " << sizeof(long long) << endl
		 << "float: " << sizeof(float) << endl
		 << "double: " << sizeof(double) << endl
		 << "pointer: " << sizeof(void*) << endl
		 << "string: " << sizeof(string) << endl
		 << "vector: " << sizeof(vector<char>) << endl;

	return 0;
}
