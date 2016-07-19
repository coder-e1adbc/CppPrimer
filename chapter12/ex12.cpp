auto p = new int();
auto sp = make_shared<int>();

process(sp);					// correct
process(new int());				// error: The smart pointer constructors that take pointers are explicit
process(p);						// error: The smart pointer constructors that take pointers are explicit
process(shared_ptr<int>(p));	// warning: the memory which p point to will be released.
