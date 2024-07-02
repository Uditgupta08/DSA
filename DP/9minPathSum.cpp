#include <bits/stdc++.h>
using namespace std;
int memo(vector<vector<int>> a, vector<vector<int>> dp, int n, int m, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return a[i][j];
    }
    if (i < 0 && j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = memo(a, dp, n, m, i, j - 1);
    int up = memo(a, dp, n, m, i - 1, j);
    dp[i][j] = a[i][j] + min(left, up);
    return dp[i][j];
}
int table(vector<vector<int>> a, vector<vector<int>> dp, int n, int m)
{
    // if (n == 0 && m == 0)
    // {
    //     return a[0][0];
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = a[0][0];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = a[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = a[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}
int optTable(vector<vector<int>> a, int n, int m)
{
    vector<int> pre(m, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, INT_MAX);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = a[0][0];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = a[i][j] + pre[j];
                if (j > 0)
                    left = a[i][j] + curr[j - 1];
                curr[j] = min(up, left);
            }
        }
        pre = curr;
    }
    return pre[m - 1];
}
int solve(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return memo(a, dp, n, m, n - 1, m - 1);
    // return table(a, dp, n, m);
    return optTable(a, n, m);
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ROWS AND COLUMNS : ";
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << solve(a) << endl;
}