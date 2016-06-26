#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
	Sales_item total;
	if(cin>>total)
	{
		Sales_item book;
		while(cin>>book)
		{
			if(book.isbn()==total.isbn())
				total+=book;
			else
			{
				cout<<total<<endl;
				total=book;
			}
		}
		cout<<total<<endl;
	}
	else
		cerr<<"No data!"<<endl;

	return 0;
}
