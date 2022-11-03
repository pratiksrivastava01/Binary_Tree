#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		this -> data = d;
		this -> right = NULL;
		this -> left = NULL;
	}
};

node *buildTree(node *root)
{
	int data;
	cin >> data;
root = new node(data);
	if(data == -1)
		return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
}

bool isSymmetrical(node *root1, node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return root1 == root2;
	else
		return (root1 -> data == root2 -> data) && isSymmetrical(root1 -> left, root2 -> right) && isSymmetrical(root1 -> right, root2 -> left);
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	// 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
	if(isSymmetrical)
		cout << "Yes the tree is Balanced" << endl;
	else 
		cout << "NO the tree is not Balanced" << endl;
	return 0;
}



