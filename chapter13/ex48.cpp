#include "ex47.h"
#include <vector>

using std::vector;

int main()
{
	vector<String> vec;
	String str("string");
	for (auto i = 0; i != 10; ++i)
		vec.push_back(str);

	return 0;
}
