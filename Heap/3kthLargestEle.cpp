#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << findKthLargest(nums, k) << endl;
}