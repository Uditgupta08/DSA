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
        int count0 = 0;
        int count1 = 0;
        if (s[0] == '1')
            count1++;
        else
            count0++;
        for (int i = 0; i < n-1; i++)
        {
            if (s[i] != s[i + 1])
            {
                if (s[i + 1] == '1')
                    count1++;
                else
                    count0++;
            }
            else if (s[i] == '1')
                count1++;
        }
        if (count0 < count1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}