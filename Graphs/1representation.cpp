#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int v, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adjList(v);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> edges;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        vector<vector<int>> adj = printGraph(V, edges);
        bool empty = true;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].empty())
                continue;
            empty = false;
            break;
        }
        if (empty)
        {
            cout << "[]\n";
            continue;
        }
        for (int i = 0; i < V; i++)
        {
            set<int> st(adj[i].begin(), adj[i].end());
            cout << "[";
            auto it = st.begin();

            while (it != st.end())
            {
                cout << *it;
                if (next(it) != st.end())
                    cout << " ";
                ++it;
            }
            cout << "]";
            cout << endl;
        }
    }
}