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
Node *deletemiddleOfLL(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    Node *pre = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    while (fast && fast->next)
    {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    if (pre)
    {
        pre->next = slow->next;
    }
    delete slow;
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
int main()
{
    vector<int> a = {1, 2, 3, 4};
    Node *head = constructLL(a);
    Node *middle = deletemiddleOfLL(head);
    printLL(middle);
}