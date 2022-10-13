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

int height(node *root)
{
	if (root == NULL)
		return 0;
	int ls = height(root->left);
	int rs = height(root->right);
	return 1 + max(ls, rs);
}

bool isBalanced(node *root)
{
	if (root == NULL)
		return true;
	int h1 = height(root->left);
	int h2 = height(root->right);

	if (abs(h1 - h2) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return true;
	return false;
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	if (isBalanced(root))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;
	return 0;
}
