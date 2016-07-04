double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

calc(23.4, 55.1);	// error: too many parameter.
count("abcda", 'a');
calc(66);
sum(vec.begin(), vec.end(), 3.8);
