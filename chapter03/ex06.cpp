#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string str;
	cin >> str;
	for (auto &c : str)
		c = 'X';
	cout << str << endl;

	return 0;
}
