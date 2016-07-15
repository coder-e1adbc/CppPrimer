#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::count;

int main()
{
	int val;
	vector<int> vec;
	while (cin >> val)
		vec.push_back(val);
	
	cout << count(vec.cbegin(), vec.cend(), val) << endl;

	return 0;
}
