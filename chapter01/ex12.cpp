#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int sum=0;
	for(int i=-100;i<=100;i++)
		sum+=i;
	cout<<sum<<endl;	//sum=0

	return 0;
}
