#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int ival;
	vector<int> ivec;
	while (cin >> ival)
		ivec.push_back(ival);

	return 0;
}
