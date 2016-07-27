#include "ex38.h"
#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	LengthEqual le;
	string s;
	vector<size_t> count(11,0);
	while (cin >> s)
	{
		for (size_t i = 1; i != 11; ++i)
			if (le(s, i))
				++count[i];
	}

	for (auto i = 1; i != 11; ++i)
		cout << "total " << count[i] << " word(s) with length " << i << endl;

	return 0;
}
