#include <bits/stdc++.h>
using namespace std;
int waysToClimb(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int ans = waysToClimb(n - 1) + waysToClimb(n - 2);
    return ans;
}
int main()
{
    int n;
    cout << "ENTER THE TARGET : ";
    cin >> n;
    cout << "NUMBER OF WAYS TO REACH : " << waysToClimb(n);
}