#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
Node *constructDLL(vector<int> a)
{
    if (a.empty())
        return NULL;
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], NULL, prev);
        prev->next = temp;
        prev = temp;
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
    if (head)
    {
        head->prev = NULL;
    }
    delete temp;
    return head;
}
Node *deleteFromEnd(Node *&head)
{
    if (!head || !head->next)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *nodeToDLT = temp->next;
    delete nodeToDLT;
    temp->next = NULL;
    return head;
}
Node *deleteFromPos(Node *&head, int pos)
{
    if (!head)
    {
        return head;
    }
    Node *temp = head;
    for (int i = 1; i < pos && temp; i++)
    {
        temp = temp->next;
    }
    if (!temp)
    {
        return head;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (head == temp)
        head = temp->next;
    delete temp;
    return head;
}
void printDLL(Node *head)
{
    if (!head)
    {
        cout << "DLL is empty" << endl;
    }
    Node *tail = NULL;
    while (head != NULL)
    {
        cout << head->data << " ";
        if (head->next == NULL)
        {
            tail = head;
        }
        head = head->next;
    }
    cout << endl;
    while (tail != NULL)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    head = tail;
    cout << endl;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {1, 3, 4};
    Node *head = constructDLL(a);
    Node *q = constructDLL(b);
    deleteFromStart(head);
    printDLL(head);
    cout << "DELETING FROM THE END" << endl;
    deleteFromEnd(head);
    printDLL(head);
    cout << "DELETING FROM GIVEN POSITION" << endl;
    deleteFromPos(q, 3);
    printDLL(q);
}