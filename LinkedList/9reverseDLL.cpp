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
Node *reverseDLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;
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
    printDLL(head);
    reverseDLL(head);
    printDLL(head);
}