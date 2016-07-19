struct destination;
struct connection;
connection connect(destination *);
void disconnect(connection);

void f(destination &d, ...)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
	// use c
}	// disconnect will be called.
