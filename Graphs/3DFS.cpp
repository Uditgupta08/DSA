#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adjL, int vis[], int n, vector<int> &ls)
{
    vis[n] = 1;
    ls.push_back(n);
    for (auto it : adjL[n])
    {
        if (!vis[it])
        {
            DFS(adjL, vis, it, ls);
        }
    }
}

int main()
{
    int n, m;
    cout << "ENTER THE NUMBER OF VERTICES : ";
    cin >> n;
    cout << "ENTER THE NUMBER OF EDGES : ";
    cin >> m;
    vector<vector<int>> adjL(n + 1); 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "ENTER THE EDGE : ";
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    cout << "ADJACENCY LIST -> " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j : adjL[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int vis[n + 1] = {0};
    int start = 1;
    vector<int> ls;
    DFS(adjL, vis, start, ls);

    cout << "DFS TRAVERSAL STARTING FROM 1 -> ";
    for (int node : ls)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
