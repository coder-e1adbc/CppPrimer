#include "ex21.h"
#include <memory>
#include <string>

using std::unique_ptr;
using std::string;

int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);
	int *ip = new int;
	DebugDelete()(ip);

	unique_ptr<int, DebugDelete> up(new int, DebugDelete());
	unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

	return 0;
}

