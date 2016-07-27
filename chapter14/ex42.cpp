#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::bind;
using std::count_if;
using std::find_if;
using std::transform;
using namespace std::placeholders;

int main()
{
	vector<int> ivec{1, 16, 256, 4096, 65536};
	vector<string> svec{"pooh", "pooh", "pooh", "hoop", "pooh"};

	auto cnt = count_if(ivec.cbegin(), ivec.cend(), bind(greater<int>(), _1, 1024));
	cout << cnt << endl;
	auto it = find_if(svec.cbegin(), svec.cend(), bind(not_equal_to<string>(), _1, "pooh"));
	cout << *it << endl;
	transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));
	for (const auto &val : ivec)
		cout << val << ' ';

	return 0;
}
