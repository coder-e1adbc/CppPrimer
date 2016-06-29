unsigned buf_size = 1024;

int ia[buf_size];				// ERROR: buf_size is not a const experssion 
int ia[4 * 7 - 14];
int ia[txt_size()];				// error while txt_size() is not a const experssion
char st[11] = "fundamental";	// ERROR: no space to store '\0'
