#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdio>

int main()
{
	auto line = new char[30];
	while (cin.peek() != EOF)
	{
		cin.getline(line, 30, '\n');
		cout.write(line, cin.gcount());
		if (cin)
			cout.put('\n');
		else
			cin.clear();
	}

	return 0;
}
