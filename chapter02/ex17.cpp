#include <iostream>

int main(void)
{
	int i,&ri=i;
	i=5;
	ri=10;
	std::cout<<i<<" "<<ri<<std::endl;	// out: 10 10

	return 0;
}
