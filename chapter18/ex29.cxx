class Class { };
class Base : public Class { };
class D1 : virtual public Base { };
class D2 : virtual public Base { };
class MI : public D1, public D2 { };
class Final : public MI, public Class { };

//	Class(), Base(), D1(), D2(), MI(), Class(), Final()
//	~Final(), ~Class(), ~MI(), ~D2(), ~D1(), ~Base(), ~Class()
//
//	one Base part, two Class part

Base *pb;
Class *pc;
MI *pmi;
D2 *pd2;

pb = new Class;	// error: invalid conversion from 'Class*' to 'Base*'
pc = new Final;
pmi = pb;		// error: invalid conversion from 'Base*' to 'MI*'
pd2 = pmi; 
