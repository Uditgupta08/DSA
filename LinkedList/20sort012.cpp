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
Node *sortLL(Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    if (!head)
    {
        return head;
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 1)
        {
            count1++;
        }
        else if (temp->data == 0)
        {
            count0++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (count0--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (count1--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (count2--)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> a = {0, 0, 0, 1, 0, 1, 0, 2, 1, 0, 1, 2, 0};
    Node *head = constructLL(a);
    head = sortLL(head);
    printLL(head);
}