#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

// array version
int main(void)
{
	int arr1[5] = {0, 1, 2, 3, 4};
	int arr2[5] = {0, 1, 2, 3, 5};

	auto beg1 = begin(arr1), end1 = end(arr1);
	auto beg2 = begin(arr2), end2 = end(arr2);

	while (beg1 != end1 && beg2 != end2 && *beg1 == *beg2)
		++beg1, ++beg2;
	if (beg1 == end1 && beg2 == end2)
		cout << "Equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}
//

/* vector vesion
int main(void)
{
	vector<int> vec1{0, 1, 2, 3, 4};
	vector<int> vec2{0, 1, 2, 3, 5};

	cout << ((vec1 == vec2) ? "Equal" : "Not equal") << endl;

	return 0;
}
*/
