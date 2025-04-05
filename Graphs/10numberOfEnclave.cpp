#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> a,
         vector<int> &drow, vector<int> &dcol)
{
    int n = a.size();
    int m = a[0].size();
    vis[i][j] = 1;
    for (int it = 0; it < 4; it++)
    {
        int nrow = i + drow[it];
        int ncol = j + dcol[it];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && a[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, vis, a, drow, dcol);
        }
    }
}
int numEnclaves(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && a[0][j] == 1)
        {
            dfs(0, j, vis, a, drow, dcol);
        }
        if (!vis[n - 1][j] && a[n - 1][j] == 1)
        {
            dfs(n - 1, j, vis, a, drow, dcol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && a[i][0] == 1)
        {
            dfs(i, 0, vis, a, drow, dcol);
        }
        if (!vis[i][m - 1] && a[i][m - 1] == 1)
        {
            dfs(i, m - 1, vis, a, drow, dcol);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> a = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(a);
}
