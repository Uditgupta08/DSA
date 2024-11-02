#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        string target = "1543";
        int ans = 0;
        int rs = 0, re = n - 1, cs = 0, ce = m - 1;
        while (rs <= re && cs <= ce)
        {
            string s;
            for (int i = cs; i <= ce; i++)
                s += c[rs][i];
            for (int i = rs + 1; i <= re; i++)
                s += c[i][ce];
            if (rs < re)
                for (int i = ce - 1; i >= cs; i--)
                    s += c[re][i];
            if (cs < ce)
                for (int i = re - 1; i > rs; i--)
                    s += c[i][cs];
            string ext_s = s + s.substr(0, target.size() - 1);
            for (size_t i = 0; i <= ext_s.size() - target.size(); i++)
            {
                if (ext_s.substr(i, target.size()) == target)
                    ans++;
            }
            rs++;
            re--;
            cs++;
            ce--;
        }
        cout << ans << endl;
    }
}
