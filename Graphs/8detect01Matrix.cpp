#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int it = 0; it < 4; it++)
        {
            int nrow = i + drow[it];
            int ncol = j + dcol[it];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && ans[nrow][ncol] == -1)
            {
                ans[nrow][ncol] = ans[i][j] + 1;
                q.push({nrow, ncol});
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> ans = updateMatrix(a);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
