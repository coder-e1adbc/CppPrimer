#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	size_t size = 128, curr = 0;
	auto cp = new char[size];
	char ch;
	while (cin >> cp[curr])
	{
		if (curr == size - 1)
		{
			auto new_cp = new char[size << 1];
			memcpy(new_cp, cp, size);
			delete [] cp;
			cp = new_cp;
			size <<= 1;
		}
		++curr;
	}
	cp[curr] = ' ';

	cout << cp << endl;
	delete [] cp;

	return 0;
}

