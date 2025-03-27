#include <bits/stdc++.h>
using namespace std;
int binary(vector<int> &a, int t, int low, int high)
{
    int mid = low + ((high - low) / 2);
    if (low > high)
    {
        return low;
    }
    if (a[mid] == t)
    {
        return mid;
    }
    else if (a[mid] < t)
    {
        return binary(a, t, mid + 1, high);
    }
    else
    {
        return binary(a, t, low, mid - 1);
    }
    return mid;
}
int searchInsert(vector<int> &nums, int target)
{
    return binary(nums, target, 0, nums.size() - 1);
}
int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    int t = 9;
    cout << searchInsert(a, t);
}