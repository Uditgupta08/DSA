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
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            TreeNode *mini = root->right;
            while (mini->left != NULL)
            {
                mini = mini->left;
            }
            root->val = mini->val;
            root->right = deleteNode(root->right, mini->val);
        }
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
    int delVal = 6;
    deleteNode(root, delVal);
    cout << "Tree after deleting " << delVal << ":" << endl;
    printTree(root);
}