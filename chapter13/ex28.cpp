class TreeNode {
public:
	TreeNode():
		value(std::string()), count(1), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode &) = delete;
	TreeNode& operator=(const TreeNode &) = delete;
	~TreeNode();

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree():
		root(new TreeNode());
	BinStrTree(const BinStrTree &) = delete;
	BinStrTree& operator=(const BinStrTree &) = delete;
	~BinStrTree() { delete root; }

private:
	TreeNode *root;
};

TreeNode::~TreeNode()
{
	if (left)
	{
		delete left;
		left = nullptr;
	}
	if (right)
	{
		delete right;
		right = nullptr;
	}
}
