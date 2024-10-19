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
void inorder(TreeNode *root, vector<int> &a)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, a);
    a.push_back(root->val);
    inorder(root->right, a);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> a;
    inorder(root, a);
    int s = 0;
    int n = a.size() - 1;
    while (s < n)
    {
        if (a[s] + a[n] == k)
        {
            return true;
        }
        else if (a[s] + a[n] < k)
        {
            s++;
        }
        else
        {
            n--;
        }
    }
    return false;
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
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    cout << "Original Tree:" << endl;
    printTree(root);
    cout << endl;
    int target = 9;
    bool result = findTarget(root, target);
    if (result)
    {
        cout << "There are two elements in the BST that sum to " << target << "." << endl;
    }
    else
    {
        cout << "There are no two elements in the BST that sum to " << target << "." << endl;
    }
}
