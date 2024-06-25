#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER : ";
    cin >> n;
    cout << "THE FACTORICAL IS : " << factorial(n) << endl;
    return 0;
}