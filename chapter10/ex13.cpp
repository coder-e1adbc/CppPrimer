#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::partition;

inline bool greater_equal_5(string &);

int main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	auto flag = partition(words.begin(), words.end(), greater_equal_5);
	auto it = words.begin();
	while (it != flag)
		cout << *it++ << ' ' ;

	return 0;
}

inline bool greater_equal_5(string &s)
{
	return s.size() >= 5;
}
