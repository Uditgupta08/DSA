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
int widthOfBinaryTree(Node* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            int m = q.front().second;
            int f, l;
            for (int i = 0; i < n; i++) {
                int curr = q.front().second - m;
                Node* node = q.front().first;
                q.pop();
                if (i == 0) {
                    f = curr;
                }
                if (i == n - 1) {
                    l = curr;
                }
                if (node->left) {
                    q.push({node->left, (long long)curr * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, (long long)curr * 2 + 2});
                }
            }
            ans = max(ans, l - f + 1);
        }
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
    cout<<"MAXIMUM WIDTH : "<<widthOfBinaryTree(root)<<endl;
}