#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	decltype(str.size()) pos(0);
	while ((pos = str.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found numbers at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_of(alphabet, pos)) != string::npos)
	{
		cout << "found alphabets at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}
	cout << endl;

	pos = 0;
	while ((pos = str.find_first_not_of(alphabet, pos)) != string::npos)
	{
		cout << "found numbers at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << "found alphabets at index: " << pos << " element is " << str[pos] << endl;
		++pos;
	}

	return 0;
}
