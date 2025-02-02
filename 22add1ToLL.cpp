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
Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;
    while (temp)
    {
        Node *newNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = newNode;
    }
    return prev;
}
Node *add1(Node *&head)
{
    if (!head)
    {
        return new Node(1);
    }
    head = reverseLL(head);
    int carry = 1;
    Node *temp = head;
    while (temp)
    {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        if (!temp->next && carry)
        {
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    head = reverseLL(head);
    return head;
}
int main()
{
    vector<int> a = {9, 9, 9};
    Node *head = constructLL(a);
    Node *ans = add1(head);
    printLL(ans);
}