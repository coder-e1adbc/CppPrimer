#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vec;
	int val;
	while (cin >> val)
		vec.push_back(val);
	for (auto &i : vec)
		i += (i % 2) ? i : 0;
    for (auto i : vec)
		cout << i << ' ';

	return 0;
}	

