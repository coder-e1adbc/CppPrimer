#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using std::getline;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::unordered_map;
using std::runtime_error;

void word_transform(ifstream &, ifstream &);

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cerr << "usage: a.exe map_file input" << endl;
		return -1;
	}

	ifstream map_file(argv[1]);
	ifstream input(argv[2]);

	word_transform(map_file, input);

	return 0;
}

unordered_map<string, string> build_map(ifstream &);
string transform(const string &, const unordered_map<string, string> &);

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = build_map(map_file);
	string line;
	while (getline(input, line))
	{
		istringstream ss(line);
		string word;
		bool first_word = true;
		while (ss >> word)
		{
			if (first_word)
				first_word = false;
			else
				cout << ' ';
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

unordered_map<string, string> build_map(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

string transform(const string &s, const unordered_map<string, string> &m)
{
	auto it = m.find(s);
	if (it == m.end())
		return s;
	else
		return it->second;
}
