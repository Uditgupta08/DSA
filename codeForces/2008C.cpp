#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        long long maxL = 0;
        long long diff = r - l;
        for (long long k = 1;; k++)
        {
            if ((k * (k + 1)) / 2 <= diff)
            {
                maxL = k;
            }
            else
            {
                break;
            }
        }
        cout << maxL + 1 << endl;
    }
    return 0;
}
