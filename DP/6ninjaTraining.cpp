#include <bits/stdc++.h>
using namespace std;
int memo(int n, int last, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, a[0][i]);
            }
        }
        return maxi;
    }
    if (dp[n][last] != -1)
        return dp[n][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int points = a[n][i] + memo(n - 1, i, a, dp);
            maxi = max(maxi, points, dp);
        }
    }
    return dp[n][last] = maxi;
}
int solve(vector<vector<int>> &a, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(a[0][1], a[0][2]);
    dp[0][1] = max(a[0][0], a[0][2]);
    dp[0][2] = max(a[0][1], a[0][0]);
    dp[0][1] = max(a[0][1], max(a[0][2], a[0][0]));
    for (int i = 1; i < n; i++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[i][last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                int point = a[i][task] + dp[i - 1][task];
                dp[i][last] = max(dp[i][last], point);
            }
        }
    }
    return dp[n - 1][3];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "ENTER THE NUMBER OF DAYS : ";
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            cout << "ENTER THE POINTS FOR DAY " << i << " : ";
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }
        cout << solve(points, n) << endl;
    }
}