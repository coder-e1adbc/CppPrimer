#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cerr << "usage: a str1 str2" << endl;
		return -1;
	}
	string str(argv[1]);
	str += argv[2];
	cout << str << endl;

	return 0;
}
