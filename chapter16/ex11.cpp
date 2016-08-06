template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();	// the same as List();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
//	void insert(ListItem<elemType> *ptr, elemType value);
	void insert(ListItem *ptr, elemType value);
private:
//	ListItem<elemType> *front, *end;
	ListItem *front, *end;
};
