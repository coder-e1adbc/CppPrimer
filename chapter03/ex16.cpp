#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	vector<int> v1;					// 0
	vector<int> v2(10);				// 10
	vector<int> v3(10, 42);			// 10
	vector<int> v4{10};				// 1
	vector<int> v5{10, 42};			// 2
	vector<string> v6{10};			// 10
	vector<string> v7{10, "hi"};	// 10

	const vector<vector<int>> ivec{v1, v2, v3, v4, v5};
	const vector<vector<string>> svec{v6, v7};
	for (auto i : ivec)
	{
		cout << i.size() << '\t';
		for (auto j : i)
			cout << j << ' ';
		cout << endl;
	}
	for (auto i : svec)
	{
		cout << i.size() << '\t';
		for (auto j : i)
			cout << j << ' ';
		cout << endl;
	}
	
	return 0;
}
