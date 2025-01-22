#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        int count = 0;
        sort(begin(a), end(a));
        for (int i = 0; i < k - 1; i++)
        {
            if (a[i] == 1)
            {
                count++;
            }
            else
            {
                count += (a[i] * 2) - 1;
            }
        }
        cout << count << endl;
    }
}