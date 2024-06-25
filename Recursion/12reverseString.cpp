#include <bits/stdc++.h>
using namespace std;
void solve(string &s, int i, int j)
{
    if (i > j)
    {
        return;
    }
    swap(s[i], s[j]);
    i++;
    j--;
    solve(s, i, j);
    return;
}
int main()
{
    string s;
    cout << "ENTER THE STRING : ";
    cin >> s;
    int n = s.length();
    solve(s, 0, n - 1);
    cout << "REVERSED STRING IS : " << s << endl;
}