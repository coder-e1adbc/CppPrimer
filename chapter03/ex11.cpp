#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	const string s = "Keep out!";
	for (auto &c : s)				// const char &c
		;
	return 0;
}
