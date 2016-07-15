#include <fstream>
#include <iterator>
#include <string>

using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;

void classify(const string &in, const string &odd, const string &even)
{
	ifstream in_fs(in);
	ofstream odd_fs(odd);
	ofstream even_fs(even);
	istream_iterator<int> in_iter(in_fs), eof;
	ostream_iterator<int> odd_iter(odd_fs, " ");
	ostream_iterator<int> even_iter(even_fs, "\n");

	int val;
	while (in_iter != eof)
	{
		val = *in_iter++;
		if (val % 2)
			*odd_iter++ = val;
		else
			*even_iter++ = val;
	}
}

#include <iostream>

using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		cerr << "usage: a.exe infile outfile1 outfile2" << endl;
		return -1;
	}
	classify(argv[1], argv[2], argv[3]);

	return 0;
}
