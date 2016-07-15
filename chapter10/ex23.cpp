#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find_if;
using std::placeholders::_1;

bool chack_size(const string &, string::size_type);

int main()
{
	const string str{"Hello, world!"};
	vector<int> vec;
	int val;
	while (cin >> val)
		vec.push_back(val);
	auto it = find_if(vec.cbegin(), vec.cend(), bind(chack_size, str, _1));
	if (it == vec.cend())
		cout << "Not found" << endl;
	else
		cout << "The first number of greater than string's length is " << *it << endl;

	return 0;
}

inline bool chack_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}
