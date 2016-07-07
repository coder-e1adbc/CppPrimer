#include "ex29.h"

using std::cout;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);		// just change the duplication
	cout << '\n';
	myScreen.display(cout);
	cout << '\n';									// will show the origin Screen

	return 0;
}
