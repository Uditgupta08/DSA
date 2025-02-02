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
Node *deleteOccurence(Node *head, int x)
{
    Node *temp = head;
    if (!head)
    {
        return head;
    }
    while (temp)
    {
        if (temp->data == x)
        {
            Node *NDL = temp;
            if (temp->prev == NULL)
            {
                head = temp->next;
                if (head)
                    head->prev = NULL;
            }
            else if (!temp->next)
            {
                temp->prev->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            delete NDL;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructDLL(a);
    printDLL(head);
    head = deleteOccurence(head, 2);
    printDLL(head);
}