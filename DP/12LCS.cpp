#include <bits/stdc++.h>
using namespace std;

int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + memo(i - 1, j - 1, s1, s2, dp);
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(memo(i - 1, j, s1, s2, dp), memo(i, j - 1, s1, s2, dp));
}
int main()
{
    string s1, s2;
    cout << "ENTER THE FIRST STRING : ";
    cin >> s1;
    cout << "ENTER THE SECOND STRING : ";
    cin >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memo(n - 1, m - 1, s1, s2, dp) << endl;
}