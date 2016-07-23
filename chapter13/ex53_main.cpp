#include "ex31.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::string;
using std::for_each;

int main()
{
	vector<HasPtr> vec;
	vec.emplace_back(string("world"));
	vec.emplace_back(string("hello"));
	for (const auto &p : vec)
		p.show();
	sort(vec.begin(), vec.end());		// not call swap but sorted ?!
	for (const auto &p : vec)
		p.show();

	return 0;
}
