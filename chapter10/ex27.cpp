#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::sort;
using std::unique_copy;
using std::for_each;
using std::back_inserter;

int main()
{
	vector<string> vec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	list<string> lst;
	sort(vec.begin(), vec.end());
	unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));
	for_each(lst.cbegin(), lst.cend(), [](const string &s) { cout << s << ' '; });

	return 0;
}
