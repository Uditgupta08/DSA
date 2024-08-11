#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int maxSum(Node *node, int &maxi)
{
    if (node == NULL)
        return 0;
    int left = max(0, maxSum(node->left, maxi));
    int right = max(0, maxSum(node->right, maxi));
    maxi = max(maxi, left + right + node->data);
    return max(left, right) + node->data;
}
int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}
int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int result = maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;
}