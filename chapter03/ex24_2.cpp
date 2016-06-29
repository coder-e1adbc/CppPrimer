#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

int main(void)
{
	int ival;
	vector<int> ivec;
	while (cin >> ival)
		ivec.push_back(ival);
	if (ivec.size() == 0)
	{
		cerr << "Illegal input!" << endl;
		return -1;
	}
	for (auto left = ivec.cbegin(), right = ivec.cend() - 1; left <= right; ++left, --right)
		cout << *left + *right << ' ';

	return 0;
}
