#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;

int main()
{
	vector<pair<string, int>> vec;
	string str;
	int val;

	while (cin >> str >> val)
	{
		vec.push_back({str, val});					// best
		vec.push_back(make_pair(str, val));
		vec.push_back(pair<string, int>(str, val));
	}

	for (const auto &p : vec)
		cout << p.first << ' ' << p.second << endl;

	return 0;
}
