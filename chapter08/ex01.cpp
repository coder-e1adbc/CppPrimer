#include <iostream>

using std::istream;
using std::cout;

istream& func(istream &is)
{
	char c;
	while (is >> c)
		cout << c << ' ';
	
	is.clear();
	return is;
}
