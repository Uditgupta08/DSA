#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *constructLL(vector<int> &a)
{
    int n = a.size();
    Node *head = new Node(a[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLL(Node *head)
{
    if (!head)
    {
        cout << "EMPTY LL" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}
Node *sortLL(Node *head)
{
    vector<int> ans;
    Node *temp = head;
    while (temp)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    sort(ans.begin(), ans.end());
    temp = constructLL(ans);
    return temp;
}
int main()
{
    vector<int> a = {4, 3, 2, 1};
    Node *head = constructLL(a);
    head = sortLL(head);
    printLL(head);
}