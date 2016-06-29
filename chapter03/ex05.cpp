#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string str, sum;
	while (cin >> str)
		sum += str;
//		sum += str + ' ';
	cout << sum << endl;

	return 0;
}
