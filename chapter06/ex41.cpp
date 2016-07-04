char *init(int ht, int wd = 80, char bckgrnd = ' ');

init();				// error
init(24, 10);
init(14, '*');		// legal but wrong	instead with init(14, 80, '*');
