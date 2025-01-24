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
Node *insertAtStart(Node *&head, int x)
{
    if (!head)
    {
        head = new Node(x);
    }
    Node *temp = head;
    Node *newNode = new Node(x);
    temp->prev = newNode;
    newNode->next = temp;
    head = head->prev;
    return head;
}
Node *insertAtEnd(Node *&head, int x)
{
    if (!head)
    {
        head = new Node(x);
    }
    Node *temp = head;
    Node *newNode = new Node(x);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
Node *insertAtPos(Node *&head, int x, int pos)
{
    Node *newNode = new Node(x);
    if (!head)
    {
        return newNode;
    }
    Node *temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL && pos != 0)
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
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
    Node *head = constructDLL(a);
    insertAtStart(head, 0);
    printDLL(head);
    cout << "INSERTING 8 AT THE END" << endl;
    insertAtEnd(head, 8);
    printDLL(head);
    cout << "INSERTING AT GIVEN POSITION" << endl;
    insertAtPos(head, 7, 8);
    printDLL(head);
}