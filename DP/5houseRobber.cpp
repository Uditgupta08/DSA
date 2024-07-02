#include <bits/stdc++.h>
using namespace std;
int optTable(vector<int> &a)
{
    long long prev1 = a[0];
    long long prev2 = 0;
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        long long take = a[i];
        if (i > 1)
            take += prev2;
        long long notTake = 0 + prev1;
        long long curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int solve(vector<int> &a)
{
    vector<int> temp1, temp2;
    int n = a.size();
    if (n == 1)
        return a[0];
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(a[i]);
        if (i != n - 1)
            temp2.push_back(a[i]);
    }
    return max(optTable(temp1), optTable(temp2));
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