#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main()
{
	string str;
	list<string> lst;
	while (cin >> str)
		lst.push_back(str);

	for (const auto &s : lst)
		cout << s << ' ' ;

	return 0;
}
