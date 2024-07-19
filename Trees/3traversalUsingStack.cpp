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
vector<int> preOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return ans;
}
vector<int> inorder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *curr = root;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}
vector<int> postorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
        ans.push_back(root->data);
    }
    return ans;
}
vector<int> postorder2(Node *root)
{
    stack<Node *> s1, s2;
    vector<int> ans;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
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
    cout << "PREORDER TRAVERSAL -> ";
    for (int i = 0; i < preOrder(root).size(); i++)
    {
        cout << preOrder(root)[i] << " ";
    }
    cout << endl;
    cout << "INORDER TRAVERSAL -> ";
    for (int i = 0; i < inorder(root).size(); i++)
    {
        cout << inorder(root)[i] << " ";
    }
    cout << endl;
    cout << "POSTORDER TRAVERSAL -> ";
    for (int i = 0; i < postorder2(root).size(); i++)
    {
        cout << postorder2(root)[i] << " ";
    }
    cout << endl;
}