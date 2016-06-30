#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	int grade;
	cin >> grade;
	// it can't be compiled successfully because "high pass" and grade < 60 are in different type
	string finalgrade = ((grade >= 90) ? "high pass" : (grade < 60)) ?	// grade >= 90		: fail
						"fail" : "pass";								// 60 <= grade < 90 : pass
																		// grade < 60		: fail
	cout << finalgrade << endl;

	return 0;
}
