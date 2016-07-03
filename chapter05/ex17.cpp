#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	const vector<int> vec1{0, 1, 1, 2};
    const vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

	decltype(vec1.size()) size = (vec1.size() < vec2.size()) ? vec1.size() : vec2.size();
	decltype(vec1.size()) index;
	for (index = 0; index != size; ++index)
		if (vec1[index] != vec2[index])
			break;
	if (index == size)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

