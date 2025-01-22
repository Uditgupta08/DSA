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
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int count = 0;
        unordered_map<int, int> prefix_sum_freq;
        int prefix_sum = 0;

        for (int i = 0; i < n; i++)
        {
            prefix_sum += a[i];
            if (prefix_sum == 0)
            {
                count++;
            }
            if (prefix_sum_freq.find(prefix_sum) != prefix_sum_freq.end())
            {
                count += prefix_sum_freq[prefix_sum];
            }
            prefix_sum_freq[prefix_sum]++;
        }

        cout << count << endl;
    }

    return 0;
}
