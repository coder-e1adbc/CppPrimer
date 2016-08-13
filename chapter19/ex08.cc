#include <iostream>
using std::cout;
using std::endl;

#include "Query.h"

int main()
{
	Query_base *p1 = new AndQuery("left", "right");
	Query_base *p2 = new OrQuery("left", "right");
	if (typeid(*p1) == typeid(*p2))
		cout << "p1 and p2 point to the same type" << endl;
	else
		cout << "p1 and p2 point to different types" << endl;
	if (typeid(*p1) == typeid(AndQuery))
		cout << "p1 points to a AndQuery" << endl;
	else
		cout << "p1 does not point to a AndQuery" << endl;
	if (typeid(*p2) == typeid(AndQuery))
		cout << "p2 points to a AndQuery" << endl;
	else
		cout << "p2 does not point to a AndQuery" << endl;

	return 0;
}
