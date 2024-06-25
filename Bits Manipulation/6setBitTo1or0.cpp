#include <bits/stdc++.h>
using namespace std;
void setTo1(int a, int change)
{
    int i = 1 << change;
    a = a | i;
    cout << a << endl;
}
void setTo0(int a, int change)
{
    int i = 1 << change;
    i = ~i;
    a = a & i;
    cout << a << endl;
}
void toggle(int a, int change)
{
    int i = 1 << change;
    a = a ^ i;
    cout << a << endl;
}
int main()
{
    int a;
    cout << "ENTER THE NUMBER : ";
    cin >> a;
    int change;
    cout << "ENTER THE BIT YOU WANT TO CHANGE : ";
    cin >> change;
    setTo0(a, change);
    setTo1(a, change);
    toggle(a, change);
}