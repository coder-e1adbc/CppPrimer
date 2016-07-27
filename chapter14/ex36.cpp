#include "ex35.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	ReadString rs;
	string s, eof;
	vector<string> vec;
	while ((s = rs()) != eof)
		vec.push_back(s);
	for (const auto s : vec)
		cout << s << endl;

	return 0;
}
