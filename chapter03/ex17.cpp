#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	string word;
	vector<string> text;
	while (cin >> word)
	{
		for (auto &c : word)
			c = toupper(c);
		text.push_back(word);
	}
	for (auto s : text)
		cout << s << endl;

	return 0;
}

