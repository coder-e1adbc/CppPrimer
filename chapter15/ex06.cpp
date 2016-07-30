#include "ex05.h"
#include <iostream>

using std::cout;

double print_total(std::ostream &, const Quote &, std::size_t);

int main()
{
	Quote item1("978-7-121-15535-2", 128);
	Bulk_quote item2("978-7-121-15535-2", 128, 5, 0.2);
	print_total(cout, item1, 10);
	print_total(cout, item2, 1);
	print_total(cout, item2, 10);

	return 0;
}
