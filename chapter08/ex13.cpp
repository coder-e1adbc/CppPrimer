#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::vector;
using std::string;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const string &);
string format(const string &);

int main()
{
	ifstream in("sstream");
	ofstream out("contacts");
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while (getline(in, line))
	{
		PersonInfo info;
		record = istringstream(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
			if (!valid(nums))
				badNums << " " << nums;
			else
				formatted << " " << format(nums);
		if (badNums.str().empty())
			out << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name
				 << "invalid number(s) " << badNums.str() << endl;
	}

	return 0;
}

bool valid(const string &str)
{
	for (const auto &c : str)
		if (!isdigit(c))
			return false;
	return true;
}

string format(const string &str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6, 4);
}
