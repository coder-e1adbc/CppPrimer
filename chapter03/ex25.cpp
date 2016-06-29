#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<unsigned> scores(11, 0);
	auto it = scores.begin();
	unsigned grade;
	while (cin >> grade)
		if (grade <= 100)
			++ *(it + grade / 10);
	for (auto i : scores)
		cout << i << ' ';

	return 0;
}
