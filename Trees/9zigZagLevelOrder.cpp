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
        val = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> zigZag(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> row(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *TreeNode = q.front();
            q.pop();
            int ind = (flag) ? i : (n - 1 - i);
            row[ind] = TreeNode->val;
            if (TreeNode->left)
            {
                q.push(TreeNode->left);
            }
            if (TreeNode->right)
            {
                q.push(TreeNode->right);
            }
        }
        flag = !flag;
        res.push_back(row);
    }
    return res;
}

void printZigZag(const vector<vector<int>> &trav)
{
    for (const auto &level : trav)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> trav = zigZag(root);
    printZigZag(trav);
    return 0;
}
