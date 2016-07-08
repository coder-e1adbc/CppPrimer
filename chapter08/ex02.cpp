#include <iostream>

using std::istream;
using std::cin;
using std::cout;

istream& func(istream &);

int main()
{
	func(cin);

	return 0;
}

istream& func(istream &is)
{
	char c;
	while (is >> c)
		cout << c << ' ';
	
	is.clear();
	return is;
}
