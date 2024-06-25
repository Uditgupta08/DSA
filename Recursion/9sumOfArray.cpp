#include <bits/stdc++.h>
using namespace std;
int solve(int *a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return a[0];
    }
    int rem = solve(a + 1, n - 1);
    int sum = a[0] + rem;
    return sum;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS OF ARRAY : ";
    cin >> n;
    cout << "ENTER THE ELEMENTS : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "THE SUM IS : " << solve(a, n) << endl;
}