#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<char> vec{'C', '+', '+'};

	string str(vec.cbegin(), vec.cend());

	cout << str << endl;

	return 0;
}
