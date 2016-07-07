#include <iostream>
#include <string>

class Person;

std::istream& read(std::istream &, Person);
std::ostream& print(std::ostream &, const Person);

class Person {

friend std::istream& read(std::istream &, Person);

public:
	Person() = default;
	Person(std::string nam, std::string add) : name(nam), addr(add) { }
	std::string showname() const { return name; }
	std::string showaddr() const { return addr; }

private:
	std::string name;
	std::string addr;

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
