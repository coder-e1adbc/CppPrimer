#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Sales_item prebook,currbook;
	int times;

	if(cin>>prebook)
	{
		times=1;
		while(cin>>currbook)
		{
			if(currbook.isbn()==prebook.isbn())
				times+=1;
			else
			{
				cout<<prebook.isbn()<<" have "<<times<<" record(s)."<<endl;
				prebook=currbook;
				times=1;
			}
		}
		cout<<prebook.isbn()<<" have "<<times<<" record(s)."<<endl;
	}
	else
		cout<<"No data."<<endl;

	return 0;
}
