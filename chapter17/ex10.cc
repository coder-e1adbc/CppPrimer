#include <bitset>
using std::bitset;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	bitset<32> bs1("00000000001000000010000100101110");
	bitset<32> bs2;
	bs2.set(1).set(2).set(3).set(5).set(8).set(13).set(21);
	cout << bs1 << endl;
	cout << bs2 << endl;

	return 0;
}
