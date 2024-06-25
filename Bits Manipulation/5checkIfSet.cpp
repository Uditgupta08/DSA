#include <bits/stdc++.h>
using namespace std;
void leftShift(int a, int check)
{
    int i;
    i = 1 << check;
    if ((a & i) != 0)
    {
        cout << "IT IS 1" << endl;
    }
    else
    {
        cout << "IT IS 0" << endl;
    }
}
void rightShift(int a, int check)
{
    int i = a >> check;
    if ((i & 1) == 0)
    {
        cout << "IT IS 0" << endl;
    }
    else
    {
        cout << "IT IS 1" << endl;
    }
}
int main()
{
    int a;
    cout << "ENTER THE NUMBER : ";
    cin >> a;
    int check;
    cout << "ENTER THE BIT YOU WANT TO CHECK IS 1 OR 0 : ";
    cin >> check;
    leftShift(a, check);
    rightShift(a, check);
}
