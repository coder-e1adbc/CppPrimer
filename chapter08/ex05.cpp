#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::vector;
using std::string;

int main()
{
	ifstream in("ex04.cpp");
	vector<string> vec;
	string str;
	while (in >> str)
		vec.push_back(str);

	return 0;
}

