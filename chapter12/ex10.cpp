void process(shared_ptr<int> ptr)
{
	// use ptr
}

shared_ptr<int> p(new int(42));	// p.use_count() = 1
process(shared_ptr<int>(p));	// p.use_count() = 1
