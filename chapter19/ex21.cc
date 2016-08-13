#include "ex21.h"
using std::ostream;
using std::endl;
using std::string;

Token& Token::operator=(const Token &t)
{
	if (tok == STR)
		if (t.tok == STR)
			sval = t.sval;
		else
			sval.~string();
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token& Token::operator=(char c)
{
	if (tok == STR)
		sval.~string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token& Token::operator=(int i)
{
	if (tok == STR)
		sval.~string();
	ival = i;
	tok = INT;
	return *this;
}

Token& Token::operator=(double d)
{
	if (tok == STR)
		sval.~string();
	dval = d;
	tok = DBL;
	return *this;
}

Token& Token::operator=(const string &s)
{
	if (tok == STR)
		sval = s;
	else
		new(&sval) string(s);
	tok = STR;
	return *this;
}

void Token::show(ostream &os) const
{
	switch (tok)  {
		case Token::INT: os << "int " << ival << endl; break;
		case Token::CHAR: os << "char " << cval << endl; break;
		case Token::DBL: os << "double " << dval << endl; break;
		case Token::STR: os << "string " << sval << endl; break;
	}
}
void Token::copyUnion(const Token &t)
{
	switch (t.tok)  {
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		case Token::STR: new(&sval) string(t.sval); break;
	}
}
