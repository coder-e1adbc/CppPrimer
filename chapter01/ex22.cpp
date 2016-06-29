#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Sales_item book,sum;
	if(cin>>sum)
	{
		while(cin>>book)
			sum+=book;
		cout<<sum<<endl;
	}
	else
		cout<<"No input."<<endl;

	return 0;
}
