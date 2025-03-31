#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int> &a, int h)
{
    int maxi = INT_MIN;
    for (auto it : a)
    {
        if (it > maxi)
        {
            maxi = it;
        }
    }
    int l = 1;
    int r = maxi;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        double tot = 0;
        for (int i = 0; i < a.size(); i++)
        {
            tot += ceil((double)a[i] / (double)m);
        }
        if (tot <= h)
        {
            r = m - 1;
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
    cout << smallestDivisor(a, 6) << endl;
}