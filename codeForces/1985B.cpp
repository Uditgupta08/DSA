#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int msum = 0;
        int opt = 2;
        for (int x = 2; x <= n; x++)
        {
            int sum = 0;
            for (int j = 1; j * x <= n; j++)
            {
                sum += j * x;
            }
            if (sum > msum)
            {
                msum = sum;
                opt = x;
            }
        }
        cout << opt << endl;
    }
}