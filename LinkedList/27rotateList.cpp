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
Node *rotateRight(Node *head, int k)
{
    if (!head || k == 0 || !head->next)
    {
        return head;
    }
    int n = 0;
    Node *temp = head;
    Node *temp3 = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    temp = head;
    k = k % n;
    if (k == 0)
    {
        return head;
    }
    k = n - k;
    while (k > 1)
    {
        temp = temp->next;
        k--;
    }
    Node *start = temp->next;
    Node *temp2 = start;
    while (temp2->next)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp3;
    temp->next = NULL;
    return start;
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
    Node *rotated = rotateRight(head, 2);
    printLL(rotated);
}