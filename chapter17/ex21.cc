#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cerr;
using std::endl;

#include <regex>
using std::regex;
using std::smatch;
using std::sregex_iterator;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const smatch &);
string format(const string &);

int main()
{
	ifstream in("phone");
	ofstream out("contacts");
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	regex r(string("(\\()?(\\d{3})(\\))?([-. ]?)(\\d{3})([-. ]?)(\\d{4})"));

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
			for (sregex_iterator it(nums.begin(), nums.end(), r), end_it;
					it != end_it; ++it)
				if (!valid(*it))
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

bool valid(const smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (!m[4].matched || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

string format(const string &str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6, 4);
}
