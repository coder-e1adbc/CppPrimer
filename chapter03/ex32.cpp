#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main(void)
{
	int ias[10];
	for (size_t i = 0; i < 10; ++i)
		ias[i] = i;

	int iad[10];
	for (size_t i = 0; i < 10; ++i)
		iad[i] = ias[i];

	return 0;
}

/* // vector version
 * int main(void)
 * {
 * 	vector<int> ivecs;
 * 	for (decltype(ivecs.size()) i = 0; i < 10; ++i)
 * 		ivecs.push_back(i);
 * 
 * 	vector<int> ivecd = ivecs;
 * 
 * 	return 0;
 * }
 */
