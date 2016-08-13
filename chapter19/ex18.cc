#include <algorithm>
using std::count_if;

#include <functional>
using std::bind;
using std::function;
using std::mem_fn;
using namespace std::placeholders;

#include <iostream>
using std::cout;
using std::endl;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <ctime>
using std::time;

int main()
{
	vector<string> vec;
	uniform_int_distribution<unsigned> u(0, 1);
	default_random_engine e(time(nullptr));
	string str[] = { string(), "string"};
	for (auto i = 0; i != 10000; ++i)
		vec.push_back(str[u(e)]);

	cout << count_if(vec.cbegin(), vec.cend(),
			function<bool (const string &)>(&string::empty)) << endl
	     << count_if(vec.cbegin(), vec.cend(), mem_fn(&string::empty)) << endl
	     << count_if(vec.cbegin(), vec.cend(), bind(&string::empty, _1));

	return 0;
}
