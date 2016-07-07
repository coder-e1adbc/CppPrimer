#include <string>

struct Person {
	std::string name;
	std::string addr;
	
	std::string showname() const { return name; }
	std::string showaddr() const { return addr; }
};
