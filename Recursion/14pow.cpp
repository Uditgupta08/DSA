#include <bits/stdc++.h>
using namespace std;
int po(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 1;
    }
    int ans;
    ans = po(a, b / 2);
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}
int main()
{
    int a, b;
    cout << "ENTER THE NUMBER AND POWER : ";
    cin >> a >> b;
    cout << a << " RAISED TO THE POWER  " << b << " IS : " << po(a, b) << endl;
}
