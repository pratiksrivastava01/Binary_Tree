#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;

		node(int d)
		{
			this -> data = d;
			this -> left = NULL;
			this -> right = NULL;
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

void zigZagTraversal(node *root)
{
	if(root == NULL)
		return;
	queue<node *> q;
	q.push(root);
	bool flag = true;
	while(!q.empty())
	{
		int size = q.size();
		for(int i = 0; i < size; i++)
		{
			node *temp = q.front();
			q.pop();
			cout << temp -> data << " ";
			if(flag)
			{
				if(temp -> left)
					q.push(temp -> left);
				if(temp -> right)
					q.push(temp -> right);
			}
			else 
			{
				if(temp -> left)
					q.push(temp -> left);
				if(temp -> right)
					q.push(temp -> right);
			}
		}
		flag = !flag;
	}
}


int main()
{
	node *root = NULL;
	root = buildTree(root);

	zigZagTraversal(root);
	cout << "\n";
}
