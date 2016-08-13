#include <iostream>
#include <string>

class Token {
public:
	Token(): tok(INT), ival(0) { }
	Token(const Token &t): tok(t.tok) { copyUnion(t); }
	Token& operator=(const Token &);
	~Token()
	{
		if (tok == STR) sval.std::string::~string();
		else if (tok == SLD) sdval.~Sales_data();
	}
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const std::string &);
	Token& operator=(const Sales_data &);
private:
	void copyUnion(const Token &);
	enum {INT, CHAR, DBL, STR, SLD} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
};
