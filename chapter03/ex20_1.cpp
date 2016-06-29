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
	if (ivec.size() > 1)
		for (decltype(ivec.size()) i = 0; i<ivec.size()-1; ++i)
			cout << ivec[i] + ivec[i+1] << ' ';
	else
		cout << ivec[0];

	return 0;
}

