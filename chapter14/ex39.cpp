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
	vector<size_t> count(2,0);
	while (cin >> s)
	{
		size_t i = 1;
		while (i != 10 && !le(s, i))
			++i;
		++count[i == 10 ? 1 : 0];
	}

	cout << "total " << count[0] << " word(s) with length less than 10" << endl
		 << "and " << count[1] << " word(s) with length 10 or more" << endl;

	return 0;
}
