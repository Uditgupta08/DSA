#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            pq.push(arr[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++)
        {
            cin >> temp[j];
        }
        arr[i] = temp;
    }
    vector<int> ans = mergeKArrays(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
