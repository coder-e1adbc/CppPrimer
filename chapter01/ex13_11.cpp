#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	cout<<"Input two numbers:"<<endl;
	int ia,ib;
	cin>>ia>>ib;
	cout<<"The numbers between "<<ia<<" and "<<ib<<" are:"<<endl;
	for(register int i=ia;i<=ib;i++)
		cout<<i<<'\t';
	cout<<endl;

	return 0;
}
