#include <iostream>
#include <map>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::function;

int add(int lhs, int rhs)
{
	return lhs + rhs;
}
struct divide {
	int operator()(int lhs, int rhs)
		{ return lhs / rhs; }
};

int main()
{
	auto mod = [](int lhs, int rhs) { return lhs % rhs; };

	map<char, function<int(int, int)>> binops = {
		{ '+', add },
		{ '-', std::minus<int>() },
		{ '*', [](int lhs, int rhs) { return lhs * rhs; } },
		{ '/', divide() },
		{ '%', mod } };
	
	int lhs, rhs;
	char op;
	while (cin >> lhs >> op >> rhs)
		cout << binops[op](lhs, rhs) << endl;

	return 0;
}
