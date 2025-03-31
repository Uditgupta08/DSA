#include <bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int> &a, int h)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (auto it : a)
    {
        maxi = max(it, maxi);
        sum += it;
    }
    int l = maxi;
    int r = sum;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        int tot = 0;
        int count = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (tot + a[i] > m)
            {
                tot = 0;
                count++;
            }
            tot += a[i];
        }
        if (count <= h)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}
int main()
{
    vector<int> a = {1, 2, 5, 9};
    cout << shipWithinDays(a, 6) << endl;
}