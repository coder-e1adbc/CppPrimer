#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char *argv[])
{
	ifstream in((argc == 1) ? "ex49.cpp" : argv[1]);

	const string ascender("bdfhijklt");
	const string descender("gjpqy");
	string word;
	string result;
	decltype(word.size()) length(0);
	while (in >> word)
		if (word.find_first_of(ascender) == string::npos && word.find_first_of(descender) == string::npos)
			if (word.size() > length)
			{
				result = word;
				length = word.size();
			}

	cout << "longest word without ascender and descender is: " << result << endl;

	return 0;
}
