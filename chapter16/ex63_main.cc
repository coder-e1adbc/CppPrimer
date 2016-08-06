#include <string>
#include <iostream>
#include <vector>
#include "ex63.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> ivec{1, 1, 2, 2, 3, 1, 1};
	vector<double> dvec{1.1, 2.2, 1.2, 3.3, 4.4, 3.3};
	vector<string> svec{"a", "a", "v", "d"};

	cout << count(ivec, 1) << endl;
	cout << count(dvec, 3.3) << endl;
	cout << count(svec, string("a")) << endl;

	return 0;
}
