#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == str2)
		cout << "Equal" <<endl;
	else
		cout << "The bigger one is: " << ((str1 > str2) ? str1 : str2) << endl;

	return 0;
}
