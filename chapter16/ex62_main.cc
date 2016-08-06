#include <iostream>
#include <unordered_set>
#include "ex62.h"

using std::cin;
using std::cout;
using std::endl;
using std::unordered_multiset;

int main()
{
	unordered_multiset<Sales_data> books;
	Sales_data book;
	while (cin >> book)
		books.insert(book);

	for (const auto &s : books)
		cout << s << endl;

	return 0;
}
