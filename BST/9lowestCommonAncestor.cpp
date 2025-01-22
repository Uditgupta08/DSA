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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
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

    TreeNode *p = root->left->left;
    TreeNode *q = root->left->right;
    TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;
}
