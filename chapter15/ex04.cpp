class Base { /*...*/ }

class Derived : public Derived { ... }	// error: a class can't derive from itself
class Derived : private Base { ... }	// correct: declaration and definition
class Derived : public Base; // error: derivation list can't appear here
