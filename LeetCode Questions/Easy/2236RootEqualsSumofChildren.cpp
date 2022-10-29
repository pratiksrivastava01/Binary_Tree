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

bool equalSum(node *root)
{
    int left = root->left->data;
    int right = root->right->data;
    if (left + right == root->data)
        return true;
    return false;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << equalSum(root) ? "true" : "false";
    return 0;
}
