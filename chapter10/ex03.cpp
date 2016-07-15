#include <iostream>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::accumulate;

int main()
{
	int val;
	vector<int> vec;
	while (cin >> val)
		vec.push_back(val);

	cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

	return 0;
}
