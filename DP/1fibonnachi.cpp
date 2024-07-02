#include <bits/stdc++.h>
using namespace std;

// int fib(int n, vector<int> &dp)
// {
//     //RECURSION AND MEMORISATION
//     if (n <= 1)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
//     return dp[n];
// }

// int fib(int n, vector<int> dp)
// {
//     //TABULTION
//     dp[0] = 0;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[n];
// }

int main()
{
    int n;
    cout << "ENTER THE NUMBER : ";
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    // cout << fib(n, dp) << endl;
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1<<endl;
    return 0;
}