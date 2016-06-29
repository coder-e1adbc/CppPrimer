#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> ivec;
	int ival;
	while (cin >> ival)
		ivec.push_back(ival);
	for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
		cout << *it + *(it + 1) << ' ';

	return 0;
}
