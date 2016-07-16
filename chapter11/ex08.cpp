#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find;

int main()
{
	vector<string> words;
	string word;
//	ver.1
	while (cin >> word)
		if (find(words.cbegin(), words.cend(), word) == words.cend())
			words.push_back(word);
//	ver.2
	while (cin >> word)
		words.push_back(word);
	elimDups(words);

	return 0;
}
