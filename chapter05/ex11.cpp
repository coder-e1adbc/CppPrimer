#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main(void)
{
	unsigned a_cnt = 0;
	unsigned e_cnt = 0;
	unsigned i_cnt = 0;
	unsigned o_cnt = 0;
	unsigned u_cnt = 0;
	unsigned space_cnt = 0;
	unsigned table_cnt = 0;
	unsigned newline_cnt = 0;

	char ch;
	while (cin >> noskipws >> ch)
		switch (ch)
		{
			case 'a': case 'A': ++a_cnt; break;
			case 'e': case 'E': ++e_cnt; break;
			case 'i': case 'I': ++i_cnt; break;
			case 'o': case 'O': ++o_cnt; break;
			case 'u': case 'U': ++u_cnt; break;
			case ' ': ++space_cnt; break;
			case '\t': ++table_cnt; break;
			case '\n': ++newline_cnt; break;
			default: break;
		}

	cout << "Number of vowel a: " << a_cnt << endl
		 << "Number of vowel e: " << e_cnt << endl
		 << "Number of vowel i: " << i_cnt << endl
		 << "Number of vowel o: " << o_cnt << endl
		 << "Number of vowel u: " << u_cnt << endl
		 << "Number of space  : " << space_cnt << endl
		 << "Number of table  : " << table_cnt << endl
		 << "Number of newline: " << newline_cnt << endl;

	return 0;
}
