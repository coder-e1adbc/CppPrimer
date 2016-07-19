#include "ex32.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &);

int main(int argc, char *argv[])
{
	ifstream infile(argc == 1 ? "ex30_main.cpp" : argv[1]);
	runQueries(infile);

	return 0;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: " ;
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}
