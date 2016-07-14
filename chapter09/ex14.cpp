#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

int main()
{
	list<const char *> lst{"Hello,", "world!"};
	vector<string> vec;

	vec.assign(lst.cbegin(), lst.cend());

	for (const auto &s : vec)
		cout << s << ' ' ;

	return 0;
}
