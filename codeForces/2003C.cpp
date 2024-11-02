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
        unordered_map<char, int> m;
        for (char ch : s)
        {
            m[ch]++;
        }
        string res = "";
        while (res.size() < n)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (m[c] > 0)
                {
                    res += c;
                    m[c]--;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
