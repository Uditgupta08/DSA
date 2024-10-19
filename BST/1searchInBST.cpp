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
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }
    else if (root->val < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);
    }
    return NULL;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    int target = 3;
    TreeNode *result = searchBST(root, target);
    if (result != NULL)
    {
        cout << "Node found with value: " << result->val << endl;
    }
    else
    {
        cout << "Node with value " << target << " not found." << endl;
    }
}