#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &a, vector<int> &dp)
{
    if (ind == 0)
        return a[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = a[ind] + f(ind - 2, a, dp);
    int notPick = 0 + f(ind - 1, a, dp);
    return dp[ind] = max(pick, notPick);
}
int table(vector<int> &a, vector<int> &dp)
{
    dp[0] = a[0];
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += dp[i - 2];
        int notTake = 0 + dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}
int optTable(vector<int> &a)
{
    int prev1 = a[0];
    int prev2 = 0;
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += prev2;
        int notTake = 0 + prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int solve(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n, -1);
    return optTable(a);
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    cout << "ENTER THE ELEMENTS : ";
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = solve(a);
    cout << "MAX SUM IS : " << sum << endl;
}