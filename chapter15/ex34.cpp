// Quary q = Quary("fiery") & Query("bird") | Query("wind");
Query(const string &);
WordQuery(const string &);
Query_base();
Query(const string &);
WordQuery(const string &);
Query_base();
Query(const string &);
WordQuery(const string &);
Query_base();
AndQuery(const Query &, const Query &);
BinaryQuery(const Query &, const Query &, string);
Query_base();
Query(shared_ptr<Query_base>);
OrQuery(const Query &, const Query &);
BinaryQuery(const Query &, const Query &, string);
Query_base();
Query(shared_ptr<Query_base>);
Query(const Query &);

// cout << q;
Query::rep();
BinaryQuery::rep();
Qyery::rep();
BinaryQuery::rep();
Query::rep();
WordQuery::rep();
Query::rep();
WordQuery::rep();
Query::rep();
WordQuery::rep();

// q.eval();
Query::eval();
OrQuery::eval();
// ...



