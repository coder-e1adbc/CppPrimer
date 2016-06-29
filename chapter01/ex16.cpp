#include <iostream>

int main(void)
{
	int val,sum=0;
	while(std::cin>>val)
		sum+=val;
	std::cout<<"Sum = "<<sum<<std::endl;

	return 0;
}
