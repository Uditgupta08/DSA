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
Node *removeNthFromEnd(Node *&head, int n)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    int rem = count - n;
    if (rem == 0)
    {
        return head->next;
    }
    temp = head;
    for (int i = 0; i < rem - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next)
    {
        temp->next = temp->next->next;
    }
    return head;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructLL(a);
    Node *odd = removeNthFromEnd(head, 6);
    printLL(odd);
}