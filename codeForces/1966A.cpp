#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[n + 1] = -1;
    int mx = 0;
    for (int i = 1, count = 0; i <= n; i++)
    {
        if (a[i] != a[i + 1])
        {
            count++;
            mx = max(mx, count);
            count = 0;
        }
        else
            count++;
    }
    if (mx < k)
    {
        cout << n << endl;
        return;
    }
    else
        cout << min(n, k - 1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}