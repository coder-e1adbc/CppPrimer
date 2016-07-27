#include "ex35.h"

using std::istream;
using std::string;

string ReadString::operator()()
{
	string s;
	is >> s;
	return s;
}
