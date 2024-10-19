#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
TreeNode *first, *second, *pre;
void recoverTree(TreeNode *root)
{
    pre = new TreeNode(INT_MIN);
    inorder(root);
    swap(first->val, second->val);
}
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    if (first == NULL && root->val < pre->val)
    {
        first = pre;
    }
    if (first != NULL && root->val < pre->val)
    {
        second = root;
    }
    pre = root;
    inorder(root->right);
}
void printTree(TreeNode *root, int space = 0, int indent = 4)
{
    if (root == NULL)
        return;
    space += indent;
    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->val << endl;
    printTree(root->left, space);
}
int main()
{
    // Construct a BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(6);  // Intentionally swap these nodes
    root->right = new TreeNode(2); // to make it invalid
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    cout << "Original Tree (with swapped nodes):" << endl;
    printTree(root);
    cout << endl;
    recoverTree(root);
    cout << "Recovered Tree:" << endl;
    printTree(root);
    cout << endl;
}
