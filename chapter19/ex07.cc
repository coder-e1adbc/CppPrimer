#include <iostream>
using std::cout;
using std::endl;

#include <typeinfo>
using std::bad_cast;

#include "Query.h"

int main()
{
	AndQuery aq("left", "right");
	OrQuery oq("left", "right");
	Query_base &q1 = aq, &q2 = oq;
	try {
		AndQuery &ra = dynamic_cast<AndQuery &>(q1);
		cout << "q1 cast succeed." << endl;
	}
	catch (bad_cast) {
		cout << "q1 cast failed." << endl;
	}
	try {
		AndQuery &ra = dynamic_cast<AndQuery &>(q2);
		cout << "q2 cast succeed." << endl;
	}
	catch (bad_cast) {
		cout << "q2 cast failed." << endl;
	}

	return 0;
}
