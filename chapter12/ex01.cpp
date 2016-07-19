StrBlob b1;								// b1 is empty
{
	StrBlob b2 = { "a", "an", "the" };	// b2 have 3 elements
	b1 = b2;							// both b1 and b2 have 3 elements
	b2.push_back("about");				// both b1 and b2 have 4 elements
}										// b1 have 4 elements, b2 destoryed.
