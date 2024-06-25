#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &a, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }
    solve(a, n - 1);
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    vector<int> a(n);
    cout << "ENTER THE ELEMETS OF ARRAY : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);
    cout << "SORTED ARRAY IS : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}