#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
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
bool isPresent(Node *head, int x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructLL(a);
    if (isPresent(head, 4))
    {
        cout << "4 IS PRESENT" << endl;
    }
    else
    {
        cout << "4 IS NOT PRESENT" << endl;
    }
    if (isPresent(head, 8))
    {
        cout << "8 IS PRESENT" << endl;
    }
    else
    {
        cout << "8 IS NOT PRESENT" << endl;
    }
}