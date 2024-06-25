#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cout << "ENTER A AND B : ";
    cin >> a >> b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "A : " << a << " B : " << b << endl;
}