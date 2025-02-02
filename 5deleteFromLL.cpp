#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
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
Node *deleteFromStart(Node *&head)
{
    if (!head)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteAtGivenPos(Node *&head, int pos)
{
    if (!head)
    {
        return head;
    }
    int n = 0;
    Node *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    if (n < pos)
    {
        cout << "INPUT VALID POSITION" << endl;
        return head;
    }
    if (pos == 1)
    {
        return deleteFromStart(head);
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *NodetoDlt = temp->next;
    temp->next = temp->next->next;
    delete (NodetoDlt);
    return head;
}
Node *deleteAtEnd(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    return head;
}
void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 7};
    Node *head = constructLL(a);
    head = deleteFromStart(head);
    printLL(head);
    head = deleteAtGivenPos(head, 3);
    printLL(head);
    head = deleteAtEnd(head);
    printLL(head);
}