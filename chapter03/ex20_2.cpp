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
	for (decltype(ivec.size()) i = 0; i < ivec.size(); ++i)
		cout << ivec[i] + ivec[ivec.size()-1-i] << ' ';

	return 0;
}

