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
bool helper(TreeNode *leftNode, TreeNode *rightNode)
{
    if (leftNode == NULL && rightNode == NULL)
        return true;
    if (leftNode == NULL || rightNode == NULL)
        return false;
    if (leftNode->val != rightNode->val)
        return false;
    return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
}
bool solve(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return helper(root->left, root->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << solve(root) << endl;
}