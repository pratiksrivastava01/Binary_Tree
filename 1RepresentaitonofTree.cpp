#include <iostream>
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
    // cout << "Enter data: "
    //  << "\n";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    // cout << "Enter left child of " << data << "\n";
    root->left = buildTree(root->left);
    // cout << "Enter right child of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}

void levelOderTraversak(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;

    // Create a tree
    root = buildTree(root);

    // Print the tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOderTraversak(root);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}
