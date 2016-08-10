#include <iostream>
using std::cin;
using std::cout;

#include "ex04.h"

int main()
{
	auto files = createFiles({"store1", "store2", "store3", "store4"});
	reportResults(cin, cout, files);

	return 0;
}
