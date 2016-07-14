#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec1{1, 2, 3, 4, 5};
	vector<int> vec2{1, 2, 3, 4 ,0};

	cout << ((vec1 == vec2) ? "vec1 == vec2" : "vec1 != vec2") << endl;

	return 0;
}
