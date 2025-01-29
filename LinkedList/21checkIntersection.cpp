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
Node *getIntersectionNode(Node *head1, Node *head2)
{
    int n1 = 0;
    int n2 = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1)
    {
        n1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        n2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (n1 > n2)
    {
        while (n1 > n2)
        {
            temp1 = temp1->next;
            n1--;
        }
    }
    else if (n1 < n2)
    {
        while (n2 > n1)
        {
            temp2 = temp2->next;
            n2--;
        }
    }
    while (temp1)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main()
{
    vector<int> a = {3, 4, 5};
    Node *head1 = constructLL(a);
    vector<int> b = {2, 4, 5};
    Node *head2 = constructLL(b);
    Node *ans = getIntersectionNode(head1, head2);
    printLL(ans);
}