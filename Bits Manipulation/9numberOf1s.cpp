#include <bits/stdc++.h>
using namespace std;
int check(int a)
{
    int count = 0;
    while (a != 0)
    {
        a = (a & (a - 1));
        count++;
    }
    return count;
}
int main()
{
    int a;
    cout << "ENTER THE NUMBER YOU WANT TO CHECK : ";
    cin >> a;
    cout << "NUMBERS OF 1 ARE : " << check(a) << endl;
}