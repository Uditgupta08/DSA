#include <bits/stdc++.h>
using namespace std;
int memo(int i, int m, int j, int n, vector<vector<int>> &dp)
{
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
    int right = memo(i, m, j + 1, n, dp);
    int down = memo(i + 1, m, j, n, dp);
    dp[i][j] = right + down;
    return dp[i][j];
}
int table(int m, int n, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                else
                    up = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                else
                    left = 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int optTable(int n, int m, vector<vector<int>> &dp)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[n - 1];
}
int solve(int m, int n)
{
    if (n == 0 && m == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return optTable(m, n, dp);
}
int main()
{
    int n, m;
    cout << "ENTER THE NUMBER OF ROWS AND COLUMNS : ";
    cin >> m >> n;
    cout << solve(m, n) << endl;
}