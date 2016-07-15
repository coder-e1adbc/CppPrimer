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
	double val;
	vector<double> vec;
	while (cin >> val)
		vec.push_back(val);

	cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl		// use int plus( remove the decimal portion)
		 << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl;

	return 0;
}
