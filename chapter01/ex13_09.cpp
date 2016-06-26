#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	short sum=0;
	for(register short i=50;i<=100;i++)
		sum+=i;
	cout<<sum<<endl;

	return 0;
}
