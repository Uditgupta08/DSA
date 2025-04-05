#include <bits/stdc++.h>
using namespace std;
int ladderLength(string s, string e, vector<string> &b)
{
    queue<pair<string, int>> q;
    q.push({s, 1});
    unordered_set<string> st(b.begin(), b.end());
    st.erase(s);
    while (!q.empty())
    {
        string curr = q.front().first;
        int ans = q.front().second;
        q.pop();
        if (curr == e)
        {
            return ans;
        }
        for (int i = 0; i < curr.size(); i++)
        {
            char ini = curr[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                curr[i] = ch;
                if (st.find(curr) != st.end())
                {
                    st.erase(curr);
                    q.push({curr, ans + 1});
                }
            }
            curr[i] = ini;
        }
    }
    return 0;
}
int main()
{
    vector<string> b = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength("hit", "cog", b);
}
