#include "ex11.h"

int main()
{
	Quote item1("978-7-121-15535-2", 128);
	Bulk_quote item2("978-7-121-15535-2", 128, 5, 0.2);
	item1.debug();
	item2.debug();

	return 0;
}
