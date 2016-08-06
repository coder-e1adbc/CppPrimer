#include <iostream>
#include "ex61_Blob.h"

using std::cout;
using std::endl;

int main()
{
	Blob<int> b;
	for (auto i(0); i != 10; ++i)
		b.push_back(i);

	while (b.size())
	{
		cout << b.back() << endl;
		b.pop_back();
	}

	return 0;
}
