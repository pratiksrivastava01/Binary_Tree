#include <iostream>
#include <map>
#include <queue>
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

void bottomView(node *root)
{
	if (root == NULL)
		return;
	map<int, int> m;
	queue<pair<node *, int>> q;
	q.push({root, 0});
	while (!q.empty())
	{
		auto it = q.front();
		q.pop();
		node *temp = it.first;
		int d = it.second;
		m[d] = temp->data;
		if (temp->left)
			q.push({temp->left, d - 1});
		if (temp->right)
			q.push({temp->right, d + 1});
	}
	for (auto it : m)
		cout << it.second << " ";
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	bottomView(root);
	return 0;
}
