#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &a, int t)
{
    int l = 0;
    int h = a.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] == t)
        {
            return mid;
        }
        else if (a[mid] >= a[l])
        {
            if (t >= a[l] && t <= a[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (t <= a[h] && t >= a[mid])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    int t = 0;
    cout << search(a, t);
}