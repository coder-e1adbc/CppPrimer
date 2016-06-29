const int v2 = 0;	// top-level const
int v1 = v2;
int *p1 = &val, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;	// p2: low-level const
												// p3: low-level and top-level
												// r2: low-level const
