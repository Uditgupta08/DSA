#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int q;
        cin >> q;
        int ans = 0;
        for (int i = 0; i <= n - 4; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                ans++;
            }
        }
        while (q--)
        {
            int p;
            int v;
            cin >> p >> v;
            p--;
            int low = max(0, p - 3);
            int high = min(n - 4, p);
            for (int i = low; i <= high; i++)
            {
                if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
                {
                    ans--;
                }
            }
            s[p] = v + '0';
            for (int i = low; i <= high; i++)
            {
                if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
                {
                    ans++;
                }
            }
            if (ans > 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}

