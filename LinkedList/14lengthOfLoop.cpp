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
Node *detectCycle(Node *head)
{
    unordered_map<Node *, int> m;
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (m[temp])
        {
            return temp;
        }
        m[temp] = count;
        count++;
        temp = temp->next;
    }
    return NULL;
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
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructLL(a);
    Node *temp = detectCycle(head);
    printLL(temp);
}