#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void helper(Node *root, vector<int> &arr, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(arr);
    }
    helper(root->left, arr, ans);
    helper(root->right, arr, ans);
    arr.pop_back();
}
vector<vector<int>> solve(Node *root)
{
    vector<vector<int>> ans;
    vector<int> temp;
    if (root == NULL)
    {
        return ans;
    }
    helper(root, temp, ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> ans = solve(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}