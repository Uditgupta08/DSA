#include <bits/stdc++.h>
using namespace std;
bool solved(int *a, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        bool ans = solved(a + 1, n - 1);
        return ans;
    }
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (solved(a, n))
    {
        cout << "SORTED" << endl;
    }
    else
    {
        cout << "NOT SORTED" << endl;
    }
}