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
bool solve(TreeNode *root, TreeNode *mini, TreeNode *maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if ((mini != NULL && root->val <= mini->val) || (maxi != NULL && root->val >= maxi->val))
    {
        return false;
    }
    return solve(root->left, mini, root) && solve(root->right, root, maxi);
}
bool isValidBST(TreeNode *root)
{
    return solve(root, NULL, NULL);
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
    cout << "Is BST: " << isValidBST(root) << endl;
}