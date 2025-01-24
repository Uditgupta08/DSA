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
Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    while (head)
    {
        Node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
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
    head = reverseLL(head);
    printLL(head);
}