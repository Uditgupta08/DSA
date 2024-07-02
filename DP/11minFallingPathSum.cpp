#include <bits/stdc++.h>
using namespace std;
int memo(vector<vector<int>> a, vector<vector<int>> dp, int n, int i, int j)
{
    if (j < 0 || j >= n)
    {
        return INT_MAX;
    }
    if (i == 0)
    {
        return a[0][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = memo(a, dp, n, i - 1, j - 1);
    int right = memo(a, dp, n, i - 1, j + 1);
    int up = memo(a, dp, n, i - 1, j);
    dp[i][j] = a[i][j] + min(left, min(right, up));
}
void table(vector<vector<int>> &a, vector<vector<int>> &dp, int n)
{
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = a[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = INT_MAX, right = INT_MAX;
            if (j > 0)
                left = dp[i - 1][j - 1];
            else
                left = INT_MAX;
            if (j < n - 1)
                right = dp[i - 1][j + 1];
            else
                right = INT_MAX;
            int up = dp[i - 1][j];
            dp[i][j] = a[i][j] + min(up, min(left, right));
        }
    }
}
void optTable(vector<vector<int>> &a, int n, int &mini)
{
    vector<int> prev(n), curr(n);
    for (int j = 0; j < n; j++)
    {
        prev[j] = a[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = INT_MAX, right = INT_MAX;
            if (j > 0)
                left = prev[j - 1];
            else
                left = INT_MAX;
            if (j < n - 1)
                right = prev[j + 1];
            else
                right = INT_MAX;
            int up = prev[j];
            curr[j] = a[i][j] + min(up, min(left, right));
        }
        prev = curr;
    }
    mini = *min_element(prev.begin(), prev.end());
}
int solve(vector<vector<int>> a)
{
    int n = a.size();
    int mini = INT_MAX;
    optTable(a, n, mini);
    // for (int j = 0; j < n; j++)
    // {
    //     mini = min(mini, dp[n - 1][j]);
    // }
    return mini;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ROWS : ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << solve(a) << endl;
}