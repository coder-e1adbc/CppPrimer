#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::vector;
using std::string;

int main(int argc, char *argv[])
{
	ifstream in((argc == 1) ? "ex29.cpp" : argv[1]);
	if (!in)
	{
		cerr << "open failed." << endl;
		return -1;
	}

	istream_iterator<string> in_it(in), eof;
	vector<string> vec(in_it, eof);
	for (const auto &s : vec)
		cout << s << ' ';

	return 0;
}
