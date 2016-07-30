#include "ex30.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
	Basket items;
	items.add_item(Bulk_quote("345", 45, 3, .15));
	items.add_item(Bulk_quote("345", 45, 3, .15));
	items.add_item(Bulk_quote("345", 45, 3, .15));
	items.add_item(Bulk_quote("678", 55, 5, .25));
	items.add_item(Bulk_quote("678", 55, 5, .25));
	items.add_item(Bulk_quote("678", 55, 5, .25));
	items.add_item(Bulk_quote("678", 55, 5, .25));
	items.add_item(Bulk_quote("678", 55, 5, .25));
	items.total_receipt(cout);

	return 0;
}
	
