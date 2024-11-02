#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = i + 1;
        }
        reverse(a.begin(), a.end());
        reverse(a.begin() + (n - m), a.end());
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, k;
//         cin >> n >> m >> k;
//         vector<int> a;

//         // First segment from k down to m + 1
//         for (int i = k; i > m; i--)
//         {
//             a.push_back(i);
//         }
//         // Second segment from m down to 1
//         for (int i = m; i >= 1; i--)
//         {
//             a.push_back(i);
//         }
//         // Third segment from k + 1 to n
//         for (int i = k + 1; i <= n; i++)
//         {
//             a.push_back(i);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
