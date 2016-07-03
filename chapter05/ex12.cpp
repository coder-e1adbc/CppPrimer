#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main(void)
{
	unsigned ff_cnt = 0;
	unsigned fl_cnt = 0;
	unsigned fi_cnt = 0;
	bool f = false;

	char ch;
	while (cin >> noskipws >> ch)
	{
		if (f)
			switch (ch)
			{
				case 'f': ++ff_cnt; break;
				case 'l': ++fl_cnt; break;
				case 'i': ++fi_cnt; break;
				default: break;
			}
		f = (ch == 'f') ? true : false;
	}

	cout << "Number of ff: " << ff_cnt << endl
		 << "Number of fl: " << fl_cnt << endl
		 << "Number of fi: " << fi_cnt << endl;

	return 0;
}
