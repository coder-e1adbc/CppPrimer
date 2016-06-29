for (auto itt = text.cbegin(); itt != text.cend() && !itt->empty(); ++itt)
	for (auto its = itt->cbegin(); its != itt.cend(); ++its)
		cout << toupper(*its) << endl;
