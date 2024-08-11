#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    Node *p = new Node(-11);
    p->left = new Node(9);
    p->right = new Node(20);
    p->right->left = new Node(15);
    p->right->right = new Node(7);
    Node *q = new Node(-10);
    q->left = new Node(9);
    q->right = new Node(20);
    q->right->left = new Node(15);
    q->right->right = new Node(7);
    if (isSameTree(p, q))
    {
        cout << "SAME TREES" << endl;
    }
    else
    {
        cout << "NOT SAME TREES" << endl;
    }
}