#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    int v = adj.size();
    queue<int> q;
    int vis[v] = {0};
    vis[0] = 1;
    q.push(0);
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans = bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}