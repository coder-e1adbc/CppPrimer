int i = -1, &r = 0;			// refenence must be initialized
int *const p2 = &i2;
const int i = -1, &r = 0;
const int *const p3 = &i2;
const int *p1 = &i2;
const int &const r2;
const int i2 = i, &r = i;