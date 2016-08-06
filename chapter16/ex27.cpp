template <typename T> class Stack { };
void f1(Stack<char>);		// no instantiation
class Exercise {
	Stack<double> &rsd;		// no instantiation
	Stack<int> si;			// instantiation
};
int main()
{
	Stack<char> *sc;		// no instantiation
	f1(*sc);				// instantiation Stack<char>
	int iObj = sizeof(Stack<string>);	// instantiation Stack<string>
}
