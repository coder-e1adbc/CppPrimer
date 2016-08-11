namespace primerLib {
	void compute();
	void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char *, char * = nullptr);

void f()
{
//	candidate function:
//		void primerLib::compute()
//		void primerLib::compute(const void *)
//		void ::compute(int)
//		void ::compute(double, double)
//		void ::compute(char *, char *)
//	viable function:
//		void primerLib::compute(const void *) 	0 -> void *
//		void ::compute(int)						best match
//		void ::compute(double, double)			int -> double
//		void ::compute(char *, char *)			0 -> char *
	compute(0);
}
