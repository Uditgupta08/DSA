#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i].begin()+1,a[i].end());
    }
    bool same = false;
    bool diff = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < a[i].size(); j++)
        {
            for (int k = 1; k < max(a[i].size(), a[j].size()); k++)
            {
                
            }
        }
    }
}