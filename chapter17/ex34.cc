#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>

#include <cmath>
using std::sqrt;

int main()
{
	cout << "default bool values: " << true << " " << false << endl
		 << "alpha bool values: " << std::boolalpha
		 << true << " " << false << std::noboolalpha << endl;

	cout << "default: " << 20 << " " << 1024 << endl
		 << "octal: " << std::oct << 20 << " " << std::showbase << 1024 << endl
		 << "hex: " << std::hex << 20 << " " << std::uppercase << 1024
		 << std::noshowbase << std::nouppercase << endl
		 << "decimal: " << std::dec << 20 << " " << 1024 << endl;

	cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0)
		 << endl;
	cout.precision(12);
	cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0)
		 << endl;
	cout << std::setprecision(3);	
	cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0)
		 << endl;

	cout << "default format: " << 100 * sqrt(2.0) << endl
		 << "scientific: " << std::scientific << 100 * sqrt(2.0) << endl
		 << "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << endl
		 << "hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << endl
		 << "use default: " << std::defaultfloat << 100 *sqrt(2.0) << endl;

	cout << 10.0 << endl
		 << std::showpoint << 10.0 << std::noshowpoint << endl;

	int i = -16;
	double d = 3.14159;
	cout << "i: " << std::setw(12) << i << "next col" << endl
		 << "d: " << std::setw(12) << d << "next col" << endl;
	cout << std::left
		 << "i: " << std::setw(12) << i << "next col" << endl
		 << "d: " << std::setw(12) << d << "next col" << endl;
	cout << std::right
		 << "i: " << std::setw(12) << i << "next col" << endl
		 << "d: " << std::setw(12) << d << "next col" << endl;
	cout << std::internal
		 << "i: " << std::setw(12) << i << "next col" << endl
		 << "d: " << std::setw(12) << d << "next col" << endl;
	cout << std::setfill('#')
		 << "i: " << std::setw(12) << i << "next col" << endl
		 << "d: " << std::setw(12) << d << "next col" << endl
		 << std::setfill(' ');

	char ch;

	cin >> std::noskipws;
	while (cin >> ch)
		cout << ch;
	cin >> std::skipws;

	return 0;
}
