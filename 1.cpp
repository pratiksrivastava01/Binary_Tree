#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <map>
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
    //      << "\n";
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
void BFS(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
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
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2 + 1;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if (abs(h1 - h2) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return root1 == root2;
    if (root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
        return true;
    return false;
}

int miniumum(node *root)
{
    if (root == NULL)
        return INT_MAX;
    int left = miniumum(root->left);
    int right = miniumum(root->right);
    return min(root->data, min(left, right));
}

int maximumPathSum(node *root)
{
    if (root == NULL)
        return 0;
    int left = maximumPathSum(root->left);
    int right = maximumPathSum(root->right);
    int maxPath = max(left, right);
    return max(maxPath, left + right + root->data);
}

void zigzag(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }
        while (!s2.empty())
        {
            node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }
}

void zigZagUsignFlag(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    bool flag = true;
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if (flag)
            {
                if (temp->left)
                    s2.push(temp->left);
                if (temp->right)
                    s2.push(temp->right);
            }
            else
            {
                if (temp->right)
                    s2.push(temp->right);
                if (temp->left)
                    s2.push(temp->left);
            }
        }
        flag = !flag;
        while (!s2.empty())
        {
            node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if (flag)
            {
                if (temp->left)
                    s1.push(temp->left);
                if (temp->right)
                    s1.push(temp->right);
            }
            else
            {
                if (temp->right)
                    s1.push(temp->right);
                if (temp->left)
                    s1.push(temp->left);
            }
        }
        flag = !flag;
    }
}

void zigZagUsingQueue(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (flag)
            {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else
            {
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        flag = !flag;
    }
}

void verticalOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    map<int, vector<int>> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        m[temp.second].push_back(temp.first->data);
        if (temp.first->left)
            q.push({temp.first->left, temp.second - 1});
        if (temp.first->right)
            q.push({temp.first->right, temp.second + 1});
    }
    for (auto it : m)
    {
        for (auto it1 : it.second)
            cout << it1 << " ";
        cout << endl;
    }
}

void verticalOrderTraversalUsingMap(node *root)
{
    if (root == NULL)
        return;
    map<int, vector<int>> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        m[temp.second].push_back(temp.first->data);
        if (temp.first->left)
            q.push({temp.first->left, temp.second - 1});
        if (temp.first->right)
            q.push({temp.first->right, temp.second + 1});
    }
    for (auto it : m)
    {
        for (auto it1 : it.second)
            cout << it1 << " ";
        cout << endl;
    }
}

void verticalTraversalUsingRecursion(node *root, int d, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    m[d].push_back(root->data);
    verticalTraversalUsingRecursion(root->left, d - 1, m);
    verticalTraversalUsingRecursion(root->right, d + 1, m);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // node *root2 = NULL;
    // root2 = buildTree(root2);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // BFS(root);
    // cout << endl;
    // levelOderTraversak(root);
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // cout << "Height of the tree is: " << height(root) << endl;
    // cout << "Diameter of the tree is: " << diameter(root) << endl;
    // cout << "Is the tree balanced: " << isBalanced(root) << endl;
    // cout << "Is the tree identical: " << isIdentical(root, root2) << endl;
    // cout << "Minimum element in the tree is: " << miniumum(root) << endl;
    // cout << "Maximum element in the tree is: " << maximum(root) << endl;
    // cout << "Maximum path sum in the tree is: " << maximumPathSum(root) << endl;
    // zigzag(root);
    // cout << endl;
    // zigZagUsignFlag(root);
    // cout << endl;
    // zigZagUsingQueue(root);
    // cout << endl;
    verticalOrderTraversal(root);
    cout << endl;
    map<int, vector<int>> m;
    verticalTraversalUsingRecursion(root, 0, m);
    for (auto it : m)
    {
        for (auto it1 : it.second)
            cout << it1 << " ";
        cout << endl;
    }

    return 0;
}
