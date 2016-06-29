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
	for (int i = 0; i < 10; ++i)
	{
		cin >> ival;
		ivec.push_back(ival);
	}
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it *= 2;
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		cout << *it << ' ';
	
	return 0;
}
