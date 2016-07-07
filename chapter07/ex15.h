#include <iostream>
#include <string>

struct Person {
	std::string name;
	std::string addr;
	
	Person() = default;
	Person(std::string nam, std::string add) : name(nam), addr(add) { }
	std::string showname() const { return name; }
	std::string showaddr() const { return addr; }
};

std::istream& read(std::istream &is, Person per)
{
	is >> per.name >> per.addr;
	return is;
}

std::ostream& print(std::ostream &os, const Person per)
{
	os << per.showname() << per.showaddr();
	return os;
}
