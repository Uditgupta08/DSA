#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
unordered_map<TreeNode *, TreeNode *> parent;
void mapParents(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}
void BFS(TreeNode *target, int k, vector<int> &ans)
{
    queue<TreeNode *> q;
    q.push(target);
    unordered_set<TreeNode *> vis;
    vis.insert(target);
    while (!q.empty())
    {
        if (k == 0)
            break;
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !vis.count(node->left))
            {
                q.push(node->left);
                vis.insert(node->left);
            }
            if (node->right && !vis.count(node->right))
            {
                q.push(node->right);
                vis.insert(node->right);
            }
            if (parent.count(node) && !vis.count(parent[node]))
            {
                q.push(parent[node]);
                vis.insert(parent[node]);
            }
        }
        k--;
    }
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    if (!root)
        return ans;

    mapParents(root);
    BFS(target, k, ans);
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> ans = distanceK(root, root, 2);
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}
