#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::modulus;
using std::placeholders::_1;
int main()
{
	vector<int> vec{2, 4, 16, 256};
	int val(2);
	auto it = find_if(vec.cbegin(), vec.cend(), bind(modulus<int>(), _1, val));
	cout << (it == vec.cend() ? "yes" : "no") << endl;

	return 0;
}
