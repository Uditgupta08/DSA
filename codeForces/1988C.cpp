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
        int l = 0;
        vector<int> s;
        vector<int> bit;
        for (int i = 0; i < 61; i++)
        {
            if (n & (1LL << i))
            {
                l++;
                bit.push_back((1LL << i));
            }
        }
        l++;
        s.push_back(n);
        for (auto it : bit)
        {
            if (n - it > 0)
            {
                s.push_back(n - it);
            }
        }

        reverse(s.begin(), s.end());
        cout << s.size() << endl;
        for (auto it : s)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
