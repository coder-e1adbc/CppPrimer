#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(void)
{
	string curword, preword;
	unsigned times(0);
	string maxrepeat;
	unsigned maxtimes(0);

	while (cin >> curword)
	{
		if (curword == preword)
			++times;
		else
		{
			if (times > maxtimes)
			{
				maxrepeat = preword;
				maxtimes = times;
			}
			times = 1;
		}
		preword = curword;
	}
	if (times > maxtimes)
	{
		maxrepeat = curword;
		maxtimes = times;
	}
	if (maxtimes == 0)
		cerr << "Bad input" << endl;
	else if (maxtimes == 1)
		cout << "No repeated word." << endl;
	else
		cout << maxrepeat << " repeated " << maxtimes << " times." << endl;

	return 0;
}
		
