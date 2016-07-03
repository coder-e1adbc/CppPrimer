#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	const vector<string> scores{"F", "D", "C", "B", "A", "A++"};

	unsigned grade;
	string lettergrade;
	if (!(cin >> grade) || grade > 100)
	{
		cerr << "bad input!" << endl;
		return -1;
	}
	if (grade < 60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade - 50) / 10];
		if (grade < 100)
			if (grade % 10 > 7)
				lettergrade += "+";
			else if (grade % 10 < 3)
				lettergrade += "-";
	}
	cout << lettergrade << endl;

	return 0;
}

