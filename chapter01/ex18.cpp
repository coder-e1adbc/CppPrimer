#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int currval,preval,times;
	if(cin>>preval)
	{
		times=1;
		while(cin>>currval)
		{
			if(currval==preval)
				times++;
			else
			{
				cout<<preval<<" occurs "<<times<<" time(s)."<<endl;
				times=1;
				preval=currval;
			}
		}
		cout<<preval<<" occurs "<<times<<" time(s)."<<endl;
	}
	else
		cout<<"No input."<<endl;

	return 0;
}
