#include <vector>

using std::vector;

class Example {
public:
	static double rate = 6.5;			// static double rate;	
	static const int vecsize = 20;
	static vector<double> vec(vecsize);	// static vector<double> vec;
};

double Example::rate;					// double Example::rate = 6.5;
vector<double> Example::vec;			// vector<double> Example::vec(vecsize);

int main()
{
	return 0;
}
