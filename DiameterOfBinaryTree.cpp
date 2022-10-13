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

int diameter(node *root)
{
	if(root == NULL)
		return 0;
	int ls = height(root->left);
	int rs = height(root->right);
	int ans = 1 + ls + rs;
	int opt1 = diameter(root->left);
	int opt2 = diameter(root->right);
	return max(ans, max(opt1, opt2));
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	cout << "The diameter of the binary tree is :" << diameter(root) << endl;
	return 0;
}
