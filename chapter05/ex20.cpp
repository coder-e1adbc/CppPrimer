#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string curword, preword;
	while (cin >> curword)
		if (curword == preword)
		{
			cout << curword << " continuous recurred 2 times." << endl;
			return 0;
		}
		else
			preword = curword;
	cout << "No word continuous recurred 2 times." << endl;
	
	return 0;
}

