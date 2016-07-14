#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec;
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	for (vector<int>::size_type i = 0; i != 24; ++i)
		vec.push_back(i);
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	vec.reserve(50);
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	while (vec.size() != vec.capacity())
		vec.push_back(0);
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	vec.push_back(42);
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	vec.shrink_to_fit();
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;

	return 0;
}
