#include <bits/stdc++.h>
using namespace std;
int solve(int *a, int n, int t, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return -1;
    }
    if (a[mid] == t)
    {
        return mid;
    }
    if (a[mid] < t)
    {
        return solve(a, n, t, mid + 1, e);
    }
    else
    {
        return solve(a, n, t, s, mid-1);
    }
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    int a[n];
    cout << "ENTER THE SORTED ARAY : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cout << "ENTER THE TARGET ELEMENT : ";
    cin >> t;
    if (solve(a, n, t, 0, n) == -1)
    {
        cout << "NOT PRESENT" << endl;
    }
    else
    {
        cout << "THE ELEMENT IS PRESENT AT INDEX : " << solve(a, n, t, 0, n) << endl;
    }
}