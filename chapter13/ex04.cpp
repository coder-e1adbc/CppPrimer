class Point;

Point global;
Point foo_bar(Point arg)							// copy constructor
{
	Point local = arg, *heap = new Point(global);	// local: copy constructor
	*heap = local;									// copy constructor
	Point pa[4] = {local, *heap};					// pa[0], pa[1]: copy constructor
	return *heap;									// copy constructor
}
