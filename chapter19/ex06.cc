#include <iostream>
using std::cout;
using std::endl;

#include "Query.h"

int main()
{
	Query_base *p1 = new AndQuery("left", "right");
	Query_base *p2 = new OrQuery("left", "right");
	if (AndQuery *pa = dynamic_cast<AndQuery *>(p1))
		cout << "p1 cast succeed." << endl;
	else
		cout << "p1 cast failed." << endl;
	if (AndQuery *pa = dynamic_cast<AndQuery *>(p2))
		cout << "p2 cast succeed." << endl;
	else
		cout << "p2 cast failed." << endl;

	return 0;
}
