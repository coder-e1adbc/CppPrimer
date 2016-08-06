#include <iostream>
#include <vector>
#include "ex64.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<const char *> vec{"asd", "asd", "as", "va", "ds"};

	cout << count(vec, "asd") << endl;

	return 0;
}
