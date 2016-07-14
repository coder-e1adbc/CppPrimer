#include <vector>

using std::vector;

vector<int>::const_iterator find(vector<int>::const_iterator beg, vector<int>::const_iterator end, int val)
{
	for ( ; beg != end; ++beg)
		if (*beg == val)
			break;

	return beg;
}
