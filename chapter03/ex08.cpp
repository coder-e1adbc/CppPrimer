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

	// while version
	decltype (str.size()) index = 0;
	while (index < str.size())
		str[index++] = 'X';

	// for version
	// for (decltype (str.size()) index = 0; index < str.size(); ++index)
	// 		str[index] = 'X';
	
	cout << str << endl;
	
	return 0;
}
