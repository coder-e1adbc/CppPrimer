#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::map;
using std::string;
using std::tolower;
using std::isalpha;
using std::find_if;
using std::find_if_not;

void standard(stringstream &, string &);

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		stringstream buff;
		standard(buff, word);
		while (buff >> word)
			++word_count[word];
	}

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;

	return 0;
}

void standard(stringstream & buff, string &word)
{
	for (auto &c : word)
		tolower(c);
	auto beg = word.cbegin();
	decltype(beg) end;
	while (beg != word.cend())
	{
		end = find_if_not(beg, word.cend(), [](char c) { return isalpha(c); });	// I don't know why must use lambda.
		buff << string(beg, end) << ' ';
		beg = find_if(end, word.cend(), [](char c) { return isalpha(c); });
	}
}
