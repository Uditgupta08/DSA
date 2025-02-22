#include <bits/stdc++.h>
using namespace std;
int orangeRotting(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }
    int time = 0;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        time = max(time, t);

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && a[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && vis[i][j] != 2)
            {
                return -1;
            }
        }
    }
    return time;
}

int main()
{
    vector<vector<int>> a = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangeRotting(a) << endl;
}
