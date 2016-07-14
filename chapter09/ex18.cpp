#include <iostream>
#include <string>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

int main()
{
	string str;
	deque<string> deq;
	while (cin >> str)
		deq.push_back(str);

	for (const auto &s : deq)
		cout << s << ' ' ;

	return 0;
}
