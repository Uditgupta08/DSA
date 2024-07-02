#include <bits/stdc++.h>
using namespace std;
int memo(vector<vector<int>> &a, int i, int m, int j, int n, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && a[i][j] == 1)
        return 0;
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = 0;
    if (j + 1 < n)
        right = memo(a, i, m, j + 1, n, dp);
    int down = 0;
    if (i + 1 < n)
        down = memo(a, i + 1, m, j, n, dp);
    dp[i][j] = right + down;
    return dp[i][j];
}
int solve(vector<vector<int>> a, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    if (n == 0 || m == 0 || a[0][0] == 1 || a[m - 1][n - 1] == 1)
    {
        return 0;
    }
    return memo(a, 0, m, 0, n, dp);
}
int main()
{
    int n, m;
    cout << "ENTER THE NUMBER OF ROWS AND COLUMNS : ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << solve(a, m, n) << endl;
}