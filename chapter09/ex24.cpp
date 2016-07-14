#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec;
	cout << vec.at(0) << endl
		 << vec[0] << endl
		 << vec.front() << endl
		 << *vec.cbegin() << endl;

	return 0;
}
