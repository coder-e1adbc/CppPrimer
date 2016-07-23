#ifndef EMPLOYEE
#define EMPLOYEE

#include <string>

class Employee {
public:
	Employee() = default;
	Employee(std::string &s): name(s), id(count++) { }
private:
	static size_t count;
	std::string name;
	size_t id;
};

size_t Employee::count = 0;

#endif
