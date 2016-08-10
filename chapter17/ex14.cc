#include <iostream>
using std::cout;
using std::endl;

#include <regex>
using std::regex;
using std::regex_error;

int main()
{
	try
	{
		regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	return 0;
}
