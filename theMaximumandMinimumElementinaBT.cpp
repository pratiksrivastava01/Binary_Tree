#include <iostream>
#include <limits.h>
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

int minimum(node *root)
{
	if (root == NULL)
		return INT_MAX;
	int left = minimum(root->left);
	int right = minimum(root->right);
	return min(root->data, min(left, right));
}

int maximum(node *root)

{
	if (root == NULL)
		return INT_MIN;
	int left = maximum(root->left);
	int right = maximum(root->right);
	return max(root->data, max(left, right));
}
int main()
{
	node *root = NULL;
	root = buildTree(root);
	cout << "The minimum element in th Binary Tree is: " << minimum(root) << endl;
	cout << "The maximum element in th Binary Tree is: " << maximum(root) << endl;
	return 0;
}
