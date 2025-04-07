#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> findLadders(string s, string e, vector<string> &b)
// {
//     unordered_set<string> st(b.begin(), b.end());
//     queue<vector<string>> q;
//     q.push({s});
//     vector<string> used;
//     used.push_back(s);
//     int lvl = 0;
//     vector<vector<string>> ans;
//     while (!q.empty())
//     {
//         vector<string> curr = q.front();
//         q.pop();
//         if (curr.size() > lvl)
//         {
//             lvl++;
//             for (auto it : used)
//             {
//                 st.erase(it);
//             }
//             used.clear();
//         }
//         string word = curr.back();
//         if (word == e)
//         {
//             if (ans.size() == 0)
//             {
//                 ans.push_back(curr);
//             }
//             else if (ans[0].size() == curr.size())
//             {
//                 ans.push_back(curr);
//             }
//         }
//         for (int i = 0; i < word.size(); i++)
//         {
//             char ini = word[i];
//             for (char ch = 'a'; ch <= 'z'; ch++)
//             {
//                 word[i] = ch;
//                 if (st.count(word) > 0)
//                 {
//                     curr.push_back(word);
//                     q.push(curr);
//                     used.push_back(word);
//                     curr.pop_back();
//                 }
//             }
//             word[i] = ini;
//         }
//     }
//     return ans;
// }
unordered_map<string, int> m;
vector<vector<string>> ans;
string b;
void dfs(string word, vector<string> &seq)
{
    if (word == b)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    int steps = m[word];
    for (int i = 0; i < word.size(); i++)
    {
        char ini = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (m.find(word) != m.end() && m[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = ini;
    }
}
vector<vector<string>> findLadders(string s, string end,
                                   vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;
    b = s;
    q.push(s);
    st.erase(s);
    m[s] = 0;
    while (!q.empty())
    {
        string word = q.front();
        q.pop();
        int steps = m[word];
        if (word == end)
            break;
        for (int i = 0; i < word.size(); i++)
        {
            char ini = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word))
                {
                    q.push(word);
                    st.erase(word);
                    m[word] = steps + 1;
                }
            }
            word[i] = ini;
        }
    }
    if (m.find(end) != m.end())
    {
        vector<string> seq;
        seq.push_back(end);
        dfs(end, seq);
    }
    return ans;
}
int main()
{
    vector<string> b = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders("hit", "cog", b);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " -> ";
        }
        cout << endl;
    }
}
