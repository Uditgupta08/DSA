#include <bits/stdc++.h>
using namespace std;
void printReverse(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printReverse(n - 1);
}
void printForward(int n)
{
    if (n == 0)
    {
        return;
    }
    printForward(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER : ";
    cin >> n;
    cout<<"REVERSE :";
    printReverse(n);
    cout<<endl;
    cout<<"FORWARD :";
    printForward(n);
}