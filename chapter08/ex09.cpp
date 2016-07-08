#include <iostream>
#include <sstream>

using std::istream;
using std::cout;
using std::istringstream;

istream& func(istream &is)
{
	char c;
	while (is >> c)
		cout << c << ' ';
	
	is.clear();
	return is;
}

int main()
{
	istringstream in("Hello,world!");
	func(in);

	return 0;
}
