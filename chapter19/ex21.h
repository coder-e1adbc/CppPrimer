#include <iostream>
#include <string>

class Token {
public:
	Token(): tok(INT), ival(0) { }
	Token(const Token &t): tok(t.tok) { copyUnion(t); }
	Token& operator=(const Token &);
	~Token() { if (tok == STR) sval.std::string::~string(); }
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const std::string &);
	void show(std::ostream & = std::cout) const;
private:
	void copyUnion(const Token &);
	enum {INT, CHAR, DBL, STR} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
};
