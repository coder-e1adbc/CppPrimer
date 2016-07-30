#include "ex36.h"

// order may be different
int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << std::endl;
	q.rep();

	return 0;
}
