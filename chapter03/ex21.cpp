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

	for (auto it1 = ivec.cbegin(); it1 != ivec.cend(); ++it1)
	{
		cout << it1->size() << '\t';
		for (auto it2 = it1->cbegin(); it2 != it1->cend(); ++it2)
			cout << *it2 << ' ';
		cout << endl;
	}
	for (auto it1 = svec.cbegin(); it1 != svec.cend(); ++it1)
	{
		cout << it1->size() << '\t';
		for (auto it2 = it1->cbegin(); it2 != it1->cend(); ++it2)
			cout << *it2 << ' ';
		cout << endl;
	}	

	return 0;
}
