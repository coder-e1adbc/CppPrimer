#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	string str;
	vector<string> svec;
	while (cin >> str)
		svec.push_back(str);

	return 0;
}
