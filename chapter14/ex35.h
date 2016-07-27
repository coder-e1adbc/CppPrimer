#ifndef READSTRING_H
#define READSTRING_H

#include <string>
#include <iostream>

class ReadString {
public:
	ReadString(std::istream &i = std::cin):
		is(i) { }
	std::string operator()();
private:
	std::istream &is;
};

#endif
