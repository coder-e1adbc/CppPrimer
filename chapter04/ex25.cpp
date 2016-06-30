#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	cout << (~'q' << 6) << endl;	// FFFFE380

	return 0;
}
