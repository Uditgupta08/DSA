#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cout << "ENTER THE NUMBER : ";
    cin >> a;
    int ans = a & (a - 1);
    cout << ans << endl;
}