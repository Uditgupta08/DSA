#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        a.push_back(n);
        int count = 0;
        while (a.size() < n)
        {
            int curr = a.back();
            a.erase(a.begin() + a.size() - 1);
            for (int i = 0; i < min(k - 1, curr - 1); i++)
            {
                a.push_back(1);
            }
            a.push_back(curr - k + 1);
            count++;
        }
        cout << count << endl;
    }
}