#include <bits/stdc++.h>
using namespace std;
int solve(int s, int g)
{
    int a = s ^ g;
    int count = 0;
    while (a != 0)
    {
        a = (a & (a - 1));
        count++;
    }
    return count;
}
int main()
{
    int s, g;
    cout << "ENTER THE START AND GOAL : ";
    cin >> s >> g;
    cout << "THE NUMBER OF FLIPS : " << solve(s, g) << endl;
}