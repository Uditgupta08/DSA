#include <bits/stdc++.h>
using namespace std;
void printReverse(string a, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << a << " " << n << endl;
    printReverse(a, n - 1);
}
void printForward(string a, int n)
{
    if (n == 0)
    {
        return;
    }
    printForward(a, n - 1);
    cout << a << " " << n << endl;
}
int main()
{
    string a;
    int n;
    cout << "ENTER THE NAME : ";
    cin >> a;
    cout << "ENTER THE TIMES YOU WANT THE NAME TO  BE PRINTED : ";
    cin >> n;
    printReverse(a, n);
    cout << "NOW FORWARD : "<<endl;
    printForward(a, n);
}