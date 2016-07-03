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
	lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
	if (grade >= 60 && grade < 100)
		lettergrade += (grade % 10 < 3) ? "-" 
					 					: (grade % 10 > 7) ? "+" : "";
	cout << lettergrade << endl;

	return 0;
}

