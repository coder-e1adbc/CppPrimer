#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string rsp;
	do {
		cout << "Please enter two strings:" << endl;
		string str1, str2;
		cin >> str1 >> str2;
		cout << "The shorter one is: "
			 << ((str1.size() < str2.size()) ? str1 : str2) << endl;
		cout << "More? yes or no: " ;
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');

	return 0;
}
