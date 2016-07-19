#include "ex19.h"
#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main()
{
	ifstream in("ex20.cpp");
	StrBlob text;
	string line;
	while (in >> line)
		text.push_back(line);

	StrBlobPtr ptr = text.begin();
	size_t curr = 0;
	while (curr != text.size())
	{
		cout << ptr.deref() << ' ';
		ptr.incr();
		++curr;
	}

	return 0;
}
