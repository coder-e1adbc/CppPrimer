// illegal: BinaryQuery is an abstract class.
BinaryQuery a = Query("fiery") & Query("bird");
// illegal: Query can not convert to AndQuery.
AndQuery b = Query("fiery") & Query("bird");
// illegal: Query can not convert to OrQuery.
OrQuery c = Query("fiery") & Query("bird");
