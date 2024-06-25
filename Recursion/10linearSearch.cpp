#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int t, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (a[i] == t)
    {
        return i;
    }
    return solve(a, n, t, i + 1);
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    int a[n];
    cout << "ENTER THE ELEMENTS : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cout << "ENTER THE TARGET ELEMENT : ";
    cin >> t;
    if (solve(a, n, t, 0) == -1)
    {
        cout << "NOT PRESENT" << endl;
    }
    else
    {
        cout << "THE ELEMENT IS PRESENT AT INDEX : " << solve(a, n, t, 0) << endl;
    }
}