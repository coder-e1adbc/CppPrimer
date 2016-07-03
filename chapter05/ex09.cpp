#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	unsigned a_cnt = 0;
	unsigned e_cnt = 0;
	unsigned i_cnt = 0;
	unsigned o_cnt = 0;
	unsigned u_cnt = 0;

	char ch;
	while (cin >> ch)
		if (ch == 'a')	++a_cnt;
		else if (ch == 'e')	++e_cnt;
		else if (ch == 'i')	++i_cnt;
		else if (ch == 'o')	++o_cnt;
		else if (ch == 'u') ++u_cnt;

	cout << "Number of vowel a: " << a_cnt << endl
		 << "Number of vowel e: " << e_cnt << endl
		 << "Number of vowel i: " << i_cnt << endl
		 << "Number of vowel o: " << o_cnt << endl
		 << "Number of vowel u: " << u_cnt << endl;

	return 0;
}
