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
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructDLL(a);
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
}