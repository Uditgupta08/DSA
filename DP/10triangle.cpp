#include <bits/stdc++.h>
using namespace std;
// int memo(vector<vector<int>> a, vector<vector<int>> dp, int n, int i, int j)
// {
//     if (i == n - 1)
//     {
//         return a[n - 1][j];
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int d = a[i][j] + memo(a, dp, n, i + 1, j);
//     int dg = a[i][j] + memo(a, dp, n, i + 1, j + 1);
//     return dp[i][j] = min(d, dg);
// }
// int table(vector<vector<int>> &a, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int j = 0; j < n; j++)
//     {
//         dp[n - 1][j] = a[n - 1][j];
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i; j >= 0; j--)
//         {
//             int d = a[i][j] + dp[i + 1][j];
//             int dg = a[i][j] + dp[i + 1][j + 1];
//             dp[i][j] = min(d, dg);
//         }
//     }
//     return dp[0][0];
// }
int optTable(vector<vector<int>> &a, int n)
{
    vector<int> front(n, 0), curr(n, 0);
    for (int j = 0; j < n; j++)
    {
        front[j] = a[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = a[i][j] + front[j];
            int dg = a[i][j] + front[j + 1];
            curr[j] = min(d, dg);
        }
        front = curr;
    }
    return front[0];
}
int main()
{
    int n;
    cout << "ENTER THE HEIGHT OF TRIANGLE : ";
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << optTable(a, n) << endl;
}