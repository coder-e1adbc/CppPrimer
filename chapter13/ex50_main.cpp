#include "ex50.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<String> vec;
	String str("string");
	for (auto i = 0; i != 10; ++i)
		vec.push_back(str);
	cout << endl;
	vec.push_back("string");
	vec.push_back("String");

	return 0;
}
