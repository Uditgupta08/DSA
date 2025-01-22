#include <bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int n)
{
    vector<pair<int, int>> ind(n);
    for (int i = 0; i < n; i++)
    {
        ind[i] = make_pair(arr[i], i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(ind[i]);
    }
    vector<int> ans(n);
    int rank = 1; 
    auto prev = pq.top();
    ans[prev.second] = rank;
    pq.pop();
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if (curr.first != prev.first)
        {
            rank++; 
        }
        ans[curr.second] = rank; 
        prev = curr;         
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<int> ans = replaceWithRank(vec, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}