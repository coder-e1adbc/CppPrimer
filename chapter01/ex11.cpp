#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int ia,ib;
	cout<<"Inter two numbers:"<<endl;
	cin>>ia>>ib;
	cout<<"The numbers between "<<ia<<" and "<<ib<<" are:"<<endl;
	int tmp=ia;
	while(tmp<=ib)
		cout<<tmp++<<'\t';

	return 0;
}
