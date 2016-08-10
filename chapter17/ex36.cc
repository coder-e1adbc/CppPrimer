#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>

#include <cmath>
using std::sqrt;

int main()
{
	cout << std::right
		 << "default format:\t" << std::setw(20) << 100 * sqrt(2.0) << endl
		 << "scientific:\t" << std::scientific << std::setw(20) 
		 << 100 * sqrt(2.0) << endl
		 << "fixed decimal:\t" << std::fixed << std::setw(20) 
		 << 100 * sqrt(2.0) << endl
		 << "hexadecimal:\t" << std::hexfloat << std::setw(20) 
		 << 100 * sqrt(2.0) << endl
		 << "use default:\t" << std::defaultfloat << std::setw(20) 
		 << 100 *sqrt(2.0)
		 << std::nouppercase << endl;

	return 0;
}
