#include "ex39.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
	ifstream infile("storyDataFile");
	TextQuery tq(infile);
	Query a = Query("Daddy");
	Query b = ~Query("Alice");
	Query c = Query("hair") | Query("Alice");
	Query d = Query("hair") & Query("Alice");
	Query q = Query("fiery") & Query("bird") | Query("wind");
	print(cout, a.eval(tq)) << endl;
	print(cout, b.eval(tq)) << endl;
	print(cout, c.eval(tq)) << endl;
	print(cout, d.eval(tq)) << endl;
	print(cout, q.eval(tq)) << endl;

	return 0;
}
