#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;

int main(int argc, char *argv[])
{
	ifstream in((argc == 1) ? "ex10.cpp" : argv[1]);
	vector<string> vec;
	string line, word;
	while (getline(in, line))
		vec.push_back(line);

	for (auto s : vec)
	{
		istringstream in(s);
		while (in >> word)
			cout << word << endl;
	}

	return 0;
}

