#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	cout<<"/*"<<endl;
	cout<<"*/"<<endl;
//	cout<</* "*/" */ <<endl;			error:missimg "\""
	cout<</* "*/" /* "/*" */<<endl;

	return 0;
}

