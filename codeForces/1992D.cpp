#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int curr = m - 1, w = 0, f = 0;
        for (auto it = 0; it < s.size(); it++)
        {
            char ch = s[it];
            if (ch == 'L')
            {
                curr = m;
            }
            else if (ch == 'W')
            {
                if (curr <= 0)
                    w++;
            }
            else
            {
                if (curr <= 0)
                    f++;
            }
            curr--;
        }

        if (w > k)
            f++;
        if (f != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}