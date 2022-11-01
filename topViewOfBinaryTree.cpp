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

void topViewOfBT(node *root)
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
		node *temperory = it.first;
		int hd = it.second;
		if (m.find(hd) == m.end())
			m[hd] = temperory->data;
		if (temperory->left)
			q.push({temperory->left, hd - 1});

		if (temperory->right)
			q.push({temperory->right, hd + 1});
	}
	for (auto it : m)
		cout << it.second << " ";
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	topViewOfBT(root);
}
