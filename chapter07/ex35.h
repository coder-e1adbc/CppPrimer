#include <string>

typedef std::string Type;

Type initVal();						// string initVal();

class Exercise {
public:
	typedef double Type;			// legal: Type(string) have not used
	Type setVal(Type);
	Type initVal();
private:
	int val;
};

Type Exercise::setVal(Type parm)	// Exercise::Type Exercise::setVal(Type parm)
{
	val = parm + initVal();			// Exercise::initVal()
	return val;
}
