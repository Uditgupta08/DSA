#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, p;
        cin >> n >> a >> b;
        if (a * 2 > b)
        {
            p = (n / 2) * b;
            p += (n % 2) * a;
        }
        else
        {
            p = a * n;
        }
        cout << p << endl;
    }
}