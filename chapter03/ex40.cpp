#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main(void)
{
	constexpr char ca1[] = "Hello, ";
	constexpr char ca2[] = "world!";
	char ca3[strlen(ca1) + strlen(ca2) + 1];
	strcpy(ca3, ca1);
	strcat(ca3, ca2);

	cout << ca3 << endl;

	return 0;
}
