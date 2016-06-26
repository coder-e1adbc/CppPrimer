#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int sum=0;
	register int i=50;
	while(i<=100)
		sum+=i++;
	cout<<"The sum from 50 to 100 is "<<sum<<endl;

	return 0;
}
