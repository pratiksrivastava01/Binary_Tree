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
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // expected output: 3
    cout << "Height of the tree is: " << height(root) << endl;
}
