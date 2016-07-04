#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector_int(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	if (beg == end)
		return;
	cout << *beg << ' ' ;
	print_vector_int(beg + 1, end);
}

int main()
{
	vector<int> vec{0, 1, 2, 3, 4, 5};
	print_vector_int(vec.begin(), vec.end());

	return 0;
}
