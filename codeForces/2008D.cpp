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
        vector<int> p(n);
        string s;
        vector<int> ans(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> cycle;
                int count = 0;
                int x = i;
                while (!vis[x])
                {
                    vis[x] = true;
                    cycle.push_back(x);
                    if (s[x] == '1')
                        count++;
                    x = p[x];
                }
                for (int idx : cycle)
                {
                    ans[idx] = count;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
