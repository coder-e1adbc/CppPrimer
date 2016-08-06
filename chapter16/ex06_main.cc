#include "ex05.h"
#include "ex06.h"

int main()
{
	int array[] = {0, 1, 2, 3, 4, 5};
	*begin(array) = 10;
	*(end(array) - 1) = 0;
	print(array);

	return 0;
}
