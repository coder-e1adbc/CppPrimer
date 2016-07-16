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

	decltype(authors.find(name)) it;
	while ((it = authors.find(name)) != authors.end())
		authors.erase(it);

	return 0;
}
