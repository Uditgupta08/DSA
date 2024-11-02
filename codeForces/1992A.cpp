#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ar[3] = {a, b, c};
        for (int i = 0; i < 5; i++)
        {
            sort(ar,ar+3);
            ar[0]++;
        }
        cout<<ar[0]*ar[1]*ar[2]<<endl;
    }
}