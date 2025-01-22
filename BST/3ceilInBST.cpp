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
int findCeil(TreeNode *root, int i)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    while (root)
    {
        if (root->val == i)
        {
            ans = root->val;
            return ans;
        }
        else if (root->val < i)
        {
            root = root->right;
        }
        else
        {
            ans = root->val;
            root = root->left;
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    int i = 2;
    cout << findCeil(root, i) << endl;
}