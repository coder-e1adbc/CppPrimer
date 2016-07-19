#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;

using size_type = vector<string>::size_type;

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	vector<string> file;
	map<string, set<size_type>> word_map;
	string text, word;
	size_type line_no = 0;
	while (getline(in, text))
	{
		istringstream line(text);
		file.push_back(text);
		while (line >> word)
		{
			word_map.insert({word, set<size_type>()}).first->second.insert(line_no);
		}
		++line_no;
	}
	in.close();

	while (cin >> word)
	{
		if (word == "q")
			break;
		auto ret = word_map.find(word);
		if (ret != word_map.end())
		{
			cout << word << " occurs " << ret->second.size() << " time(s):" << endl;
			for (auto it = ret->second.cbegin(); it != ret->second.cend(); ++it)
				cout << "\t(line " << *it << ") " << file[*it] << endl;
		} else
			cout << word << " not found." << endl;
	}

	return 0;
}
