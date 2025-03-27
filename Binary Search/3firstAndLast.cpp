#include <bits/stdc++.h>
using namespace std;
int binary(vector<int> &a, int low, int high, int t)
{
    while (low <= high)
    {
        int mid = low + (high - low / 2);
        if (a[mid] < t)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int s = binary(nums, low, high, target);
    int e = binary(nums, low, high, target + 1) - 1;
    if (s < nums.size() && nums[s] == target)
    {
        return {s, e};
    }
    return {-1, -1};
}
int main()
{
    vector<int> a = {5, 7, 7, 8, 8, 10};
    int t = 8;
    vector<int> ans = searchRange(a, t);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}