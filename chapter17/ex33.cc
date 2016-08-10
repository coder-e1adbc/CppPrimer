#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::getline;

#include <fstream>
using std::ifstream;

#include <map>
using std::map;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <sstream>
using std::istringstream;

#include <stdexcept>
using std::runtime_error;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <ctime>
using std::time;

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

map<string, vector<string>> build_map(ifstream &);
string transform(const string &, const map<string, vector<string>> &);

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

map<string, vector<string>> build_map(ifstream &map_file)
{
	map<string, vector<string>> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key].push_back(value.substr(1));
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

unsigned random_unsigned(unsigned seed, unsigned min, unsigned max)
{
    static default_random_engine e(seed);
    uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

string transform(const string &s, const map<string, vector<string>> &m)
{
	auto it = m.find(s);
	if (it == m.end())
		return s;
	else
		return it->second.at(random_unsigned(time(nullptr), 0,
					it->second.size() - 1));
}
