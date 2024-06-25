#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cout << "ENTER THE VALUES FOR A AND B : ";
    cin >> a >> b;
    int x = a & b; // AND
    int y = a | b; // OR
    int z = a ^ b; // XOR
    int n = ~a;    // NOT
    int m = ~b;    // NOT
    cout << "AND OF " << a << " AND " << b << " : " << x << endl;
    cout << "OR OF " << a << " AND " << b << " : " << y << endl;
    cout << "XOR OF " << a << " AND " << b << " : " << z << endl;
    cout << "NOT OF " << a << " IS : " << n << " AND " << b << " IS : " << m << endl;
}