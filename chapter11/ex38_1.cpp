#include <iostream>
#include <unordered_map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

int main()
{
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

	for (const auto &p : word_count)
		cout << p.first << " occurs " << p.second << " time" << ((p.second > 1) ? "s." : ".") << endl;

	return 0;
}
