#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string curword, preword;
	while (cin >> curword)
	{
		if (!isupper(curword[0]))
		{
			preword = "";
			continue;
		}
		if (curword == preword)
		{
			cout << curword << " continuous recurred 2 times." << endl;
			return 0;
		}
		preword = curword;
	}
	cout << "No word begin with a capital letter continuous recurred 2 times." << endl;
	
	return 0;
}

