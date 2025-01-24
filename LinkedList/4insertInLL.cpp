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
Node *insertAtStart(Node *&head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    return head;
}
Node *insertAtGivenPos(Node *&head, int x, int pos)
{
    int n = 0;
    Node *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    if (pos > n || pos <= 0)
    {
        cout << "Invalid position" << endl;
        return head;
    }
    if (pos == 1)
    {
        insertAtStart(head, x);
        return head;
    }
    temp = head;
    int count = 1;
    Node *newNode = new Node(x);
    while (temp && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node *insertAtEnd(Node *&head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(x);
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
    head = insertAtStart(head, 0);
    printLL(head);
    head = insertAtGivenPos(head, 6, 7);
    printLL(head);
    head = insertAtEnd(head, 8);
    printLL(head);
}