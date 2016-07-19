void process(shared_ptr<int> ptr)
{
	// use ptr
}

shared_ptr<int> p(new int(42));		// p.use_count() = 1
process(shared_ptr<int>(p.get()));	// warning: the memory which p point to will be release, should not use p again.
