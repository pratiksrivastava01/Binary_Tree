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

int maxiPath(node *root)
{
	if (root == NULL)
		return 0;
	int left = maxiPath(root->left);
	int right = maxiPath(root->right);
	int maxPath = max(left, right);
	return max(maxPath, left + right + root->data);
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	cout << "Maximum sum path in the 🌲🌲is: " << maxiPath(root) << endl;
	return 0;
}
