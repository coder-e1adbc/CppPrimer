#include <vector>

using std::vector;

bool find(vector<int>::const_iterator beg, vector<int>::const_iterator end, int val)
{
	while (beg != end)
		if (*beg++ == val)
			return true;
	return false;
}
