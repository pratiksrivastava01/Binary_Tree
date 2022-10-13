#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

node *buildTree(node *root)
{
	int data;
	cin >> data;
	root = new node(data);

	if (data == -1)
		return NULL;
	root->left = buildTree(root->left);
	root->right = buildTree(root->right);
	return root;
}

bool isIdentical(node *root1, node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return root1 == root2;
	if (root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
		return true;
	return false;
	;
}

int main()
{
	node *root1 = NULL;
	root1 = buildTree(root1);
	node *root2 = NULL;
	root2 = buildTree(root2);

	if (isIdentical(root1, root2))
		cout << "Yes the tree is Identical" << endl;
	else
		cout << "NO the tree is not Identical" << endl;
}
