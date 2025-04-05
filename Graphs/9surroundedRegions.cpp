#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &a, vector<int> dcol, vector<int> drow)
{
    int n = a.size();
    int m = a[0].size();
    vis[i][j] = 1;
    for (int it = 0; it < 4; it++)
    {
        int nrow = drow[it] + i;
        int ncol = dcol[it] + j;
        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && a[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, vis, a, drow, dcol);
        }
    }
}
void solve(vector<vector<char>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && a[i][0] == 'O')
        {
            dfs(i, 0, vis, a, dcol, drow);
        }
        if (!vis[i][m - 1] && a[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, a, dcol, drow);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!vis[0][i] && a[0][i] == 'O')
        {
            dfs(0, i, vis, a, dcol, drow);
        }
        if (!vis[n - 1][i] && a[n - 1][i] == 'O')
        {
            dfs(n - 1, i, vis, a, dcol, drow);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == 'O')
            {
                a[i][j] = 'X';
            }
        }
    }
}
int main()
{
    vector<vector<char>> a = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    solve(a);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
