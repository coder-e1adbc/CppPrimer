#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>

#include <cmath>
using std::sqrt;

int main()
{
	cout <<std::uppercase
		 << "default format: " << 100 * sqrt(2.0) << endl
		 << "scientific: " << std::scientific << 100 * sqrt(2.0) << endl
		 << "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << endl
		 << "hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << endl
		 << "use default: " << std::defaultfloat << 100 *sqrt(2.0)
		 << std::nouppercase << endl;

	return 0;
}
