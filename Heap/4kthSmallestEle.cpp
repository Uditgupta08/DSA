#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int> pq(arr.begin(), arr.end());
    for (int i = n; i > k; i--)
    {
        pq.pop();
    }
    return pq.top();
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << kthSmallest(arr, k) << endl;
}