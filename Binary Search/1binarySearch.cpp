#include <bits/stdc++.h>
using namespace std;
int binary(vector<int> &a, int t, int low, int high)
{
    int mid = low + ((high - low) / 2);
    if (low > high)
    {
        return -1;
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
    return -1;
}
int search(vector<int> &a, int t)
{
    int low = 0;
    int high = a.size() - 1;
    return binary(a, t, low, high);
}
int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    int t = 9;
    cout << search(a, t);
}