#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = lists.size();
    for (int i = 0; i < k; i++)
    {
        ListNode *curr = lists[i];
        while (curr != NULL)
        {
            pq.push(curr->val);
            curr = curr->next;
        }
    }
    if (pq.empty())
    {
        return NULL;
    }
    ListNode *res = new ListNode(pq.top());
    pq.pop();
    ListNode *tail = res;
    while (!pq.empty())
    {
        tail->next = new ListNode(pq.top());
        pq.pop();
        tail = tail->next;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<ListNode *> lists(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        ListNode *head = NULL, *tail = NULL;
        for (int j = 0; j < k; j++)
        {
            int val;
            cin >> val;
            ListNode *newNode = new ListNode(val);
            if (!head)
            {
                head = newNode;
                tail = head;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        lists[i] = head;
    }
    ListNode *res = mergeKLists(lists);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}