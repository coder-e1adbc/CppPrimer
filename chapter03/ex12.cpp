vector<vector<int>> ivec;			// ivec: 10 vector<int>
vector<string> svec = ivec;			// illegal: type not match
vector<string> svec(10, "null");	// svec = {"null", "null", ..., "null"}
