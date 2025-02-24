#include <bits/stdc++.h>
using namespace std;
bool detect(int src, vector<vector<int>> adjL, int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto adjnode : adjL[curr])
        {
            if (!vis[adjnode])
            {
                vis[adjnode] = 1;
                q.push({adjnode, curr});
            }
            else if (prev != adjnode)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int n, vector<vector<int>> adjL)
{
    int vis[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adjL, vis))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n = 7;
    vector<vector<int>> adjL(n + 1);
    adjL = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = isCycle(4, adjL);
    if (ans)
        cout << "cycle";
    else
        cout << "No cycle";
    return 0;
}