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
Node *add(Node *&head1, Node *&head2)
{
    Node *ans = new Node(0);
    Node *temp = ans;
    int carry = 0;
    while (head1 || head2 || carry)
    {
        int sum = carry;
        if (head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        temp->next = new Node(sum);
        temp = temp->next;
    }
    return ans->next;
}
int main()
{
    vector<int> a = {2, 4, 3};
    Node *head1 = constructLL(a);
    vector<int> b = {5, 6, 4};
    Node *head2 = constructLL(b);
    Node *ans = add(head1, head2);
    printLL(ans);
}