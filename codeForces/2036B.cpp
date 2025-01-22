#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<pair<int, vector<pair<int, int>>>> temp;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> bottles(k);

        for (int j = 0; j < k; j++)
        {
            int b, c;
            cin >> b >> c;
            bottles[j] = make_pair(b, c);
        }
        temp.push_back({n, bottles});
        unordered_map<int, int> bval;
        for (auto &btl : bottles)
        {
            int b = btl.first;
            int c = btl.second;
            bval[b] += c;
        }
        vector<int> topvals;
        for (auto &entry : bval)
        {
            topvals.push_back(entry.second);
        }
        sort(topvals.rbegin(), topvals.rend());
        int ans = 0;
        for (int j = 0; j < min(n, (int)topvals.size()); j++)
        {
            ans += topvals[j];
        }
        cout << ans << endl;
    }
}