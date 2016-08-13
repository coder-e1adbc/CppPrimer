#include "ex21.h"
using std::ostream;
using std::endl;
using std::string;

Token& Token::operator=(const Token &t)
{
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == SLD && t.tok != SLD) sdval.~Sales_data();
	if (tok == STR && t.tok == STR) sval = t.sval;
	else if (tok == SLD && t.tok == SLD) sdval = t.sdval;
	else copyUnion(t);
	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token &&t)
{
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == SLD && t.tok != SLD) sdval.~Sales_data();
	if (tok == STR && t.tok == STR) sval = std::move(t.sval);
	else if (tok == SLD && t.tok == SLD) sdval = std::move(t.sdval);
	else moveUnion(t);
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

Token& Token::operator=(const Sales_data &s)
{
	if (tok == SLD)
		sdval = s;
	else
	{
		if (tok == STR)
			sval.~string();
		new(&sdval) Sales_data(s);
		tok = SLD;
	}
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch (t.tok)  {
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		case Token::STR: new(&sval) string(t.sval); break;
		case Token::SLD: new(&sdval) Sales_data(t.sdval); break;
	}
}

void Token::moveUnion(Token &&t)
{
	switch (tok)  {
		case Token::INT: ival = std::move(t.ival); break;
		case Token::CHAR: cval = std::move(t.cval); break;
		case Token::DBL: dval = std::move(t.dval); break;
		case Token::STR: new(&sval) string(std::move(t.sval)); break;
		case Token::SLD: new(&sdval) Sales_data(std::move(t.sdval)); break;
	}
}
