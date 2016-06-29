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
	if (str1.size() == str2.size())
		cout << "Same length." << endl;
	else
		cout << "The longer one is "
			 << ((str1.size() > str2.size()) ? str1 : str2) << endl;

	return 0;
}
