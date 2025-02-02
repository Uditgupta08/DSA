#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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
Node *removeDuplicates(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *temp = head;
    temp = temp->next;
    while (temp)
    {
        if (temp->prev->data == temp->data)
        {
            Node *NDL = temp;
            temp = temp->prev;
            temp->next = NDL->next;
            if (NDL->next)
                NDL->next->prev = temp;
            delete NDL;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> a = {1, 1, 3, 4, 5, 5};
    Node *head = constructDLL(a);
    printDLL(head);
    head = removeDuplicates(head);
    printDLL(head);
}