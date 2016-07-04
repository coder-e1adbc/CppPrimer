#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> li)
{
	int sum(0);
	for (auto val : li)
		sum += val;
	
	return sum;
}

int main()
{
	cout << sum({1, 2, 3, 4, 5}) << endl;

	return 0;
}
