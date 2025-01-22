#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sq = sqrt(n);
        if (sq * sq != n)
        {
            cout << "NO" << endl;
            continue;
        }
        bool isBeauty = true;
        for (int i = 0; i < n; i++)
        {
            int r = i / sq;
            int c = i % sq;
            if (r == 0 || r == sq - 1 || c == 0 || c == sq - 1)
            {
                if (s[i] != '1')
                {
                    isBeauty = false;
                    break;
                }
            }
            else
            {
                if (s[i] != '0')
                {
                    isBeauty = false;
                    break;
                }
            }
        }
        if (isBeauty)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}