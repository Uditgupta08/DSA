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
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int x)
{
    // YEH TLE DEGA
    // vector<pair<int, int>> ans;
    // Node *temp1 = head;
    // while (temp1 && temp1->data < x)
    // {
    //     Node *temp2 = temp1->next;
    //     int rem = x - temp1->data;
    //     while (temp2 && rem >= temp2->data)
    //     {
    //         if (temp2->data == rem)
    //         {
    //             ans.push_back(make_pair(temp1->data, temp2->data));
    //         }
    //         temp2 = temp2->next;
    //     }
    //     temp1 = temp1->next;
    // }
    // return ans;

    // RIGHT KO LAST PE LE JAO AUR CHECK KARO KI SUM LEFT AUR RIGHT KA KITNA H
    vector<pair<int, int>> ans;
    Node *left = head;
    Node *right = head;
    while (right && right->next)
    {
        right = right->next;
        cout << right->data << " ";
    }
    cout << endl;
    while (left && right && left != right && right->next != left)
    {
        int sum = left->data + right->data;
        if (sum > x)
        {
            right = right->prev;
        }
        else if (sum < x)
        {
            left = left->next;
        }
        if (sum == x)
        {
            ans.push_back(make_pair(left->data, right->data));
            left = left->next;
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = constructDLL(a);
    printDLL(head);
    vector<pair<int, int>> ans = findPairsWithGivenSum(head, 5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}