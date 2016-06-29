#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int ia,ib;
	cout<<"Inter two numbers:"<<endl;
	cin>>ia>>ib;
	int tmp=ia;
	if(ia>ib)
	{
		tmp=ib;
		ib=ia;
		ia=tmp;
	}
	cout<<"The numbers between "<<ia<<" and "<<ib<<" are:"<<endl;
	while(tmp<=ib)
		cout<<tmp++<<'\t';

	return 0;
}
