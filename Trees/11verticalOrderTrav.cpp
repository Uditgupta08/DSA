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

vector<vector<int>> solve(TreeNode *root)
{
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        int size = todo.size();

        for (int i = 0; i < size; ++i)
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
    }
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }
    return res;
}
void print(const vector<vector<int>> &trav)
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = solve(root);
    print(ans);
}
