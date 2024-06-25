#include <bits/stdc++.h>
using namespace std;
int power(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(n - 1) * 2;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER RAISED TO POWER 2 : ";
    cin >> n;
    cout << power(n) << endl;
}