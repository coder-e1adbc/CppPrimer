#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	string str;
	vector<string> vec;
	while (cin >> str)
		vec.push_back(str);
	
	int sum(0);					// double sum(0);
	for (const auto &s : vec)
		sum += stoi(s);			// sum += stod(s);

	cout << "Sum is: " << sum << endl;

	return 0;
}
