#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main()
{
	multimap<string, string> authors;
	string name, book;
	while (cin >> name >> book)
		authors.insert({name, book});

	for (const auto &p : authors)
		cout << p.first << ' ' << p.second << endl;

	return 0;
}
