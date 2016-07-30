string s1, s2, s3, s4;

// WordQuery, WordQuery, NotQuery, AndQuery, OrQuery
Query(s1) | Query(s2) & ~Query(s3);
// the same as the previous one
Query(s1) | (Query(s2) & ~Query(s3));
//WordQuery, WordQuery, AndQuery, WordQuery, WordQuery, AndQuery, OrQuery
(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
