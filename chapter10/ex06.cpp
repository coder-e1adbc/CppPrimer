#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::fill_n;

int main()
{
	vector<int> vec{ 0, 1, 2, 3, 4, 5 };
	for (const auto &val : vec)
		cout << val << ' ' ;
	cout << endl;
	
	fill_n(vec.begin(), vec.size(), 0);
	for (const auto &val : vec)
		cout << val << ' ' ;

	return 0;
}
