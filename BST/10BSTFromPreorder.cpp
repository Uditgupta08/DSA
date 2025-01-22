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
TreeNode *bst(vector<int> &p, int &i, int maxi)
{
    if (i == p.size() || p[i] > maxi)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(p[i]);
    i++;
    root->left = bst(p, i, root->val);
    root->right = bst(p, i, maxi);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &p)
{
    int i = 0;
    return bst(p, i, INT_MAX);
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
    vector<int> preorder = {4, 2, 1, 3, 6, 5, 9};
    TreeNode *rootFromPreorder = bstFromPreorder(preorder);
    cout << "Constructed Tree from Preorder:" << endl;
    printTree(rootFromPreorder);
    cout << endl;
}
