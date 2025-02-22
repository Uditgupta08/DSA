#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>> a, int sr, int sc, int color)
{
    int n = a.size();
    int m = a[0].size();
    int ini = a[sr][sc];
    if (color == ini)
    {
        return a;
    }
    a[sr][sc] = color;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] != ini)
            {
                continue;
            }
            a[nx][ny] = color;
            q.push({nx, ny});
        }
    }
    return a;
}
int main()
{
    vector<vector<int>> a = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    cout << "INITITAL : " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    a = solve(a, sr, sc, color);
    cout << "AFTER CHANGING :" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}