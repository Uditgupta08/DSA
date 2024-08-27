#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *lca(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *p = root->left->left;
    Node *q = root->left;
    cout << lca(root, p, q)->data << endl;
}