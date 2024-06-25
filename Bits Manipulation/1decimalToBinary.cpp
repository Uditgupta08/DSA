#include <bits/stdc++.h>
using namespace std;
string convert(int n)
{
    string ans = "";
    if (n == 0)
    {
        return 0;
    }
    while (n > 0)
    {
        if (n % 2 == 1)
            ans += '1';
        else
            ans += '0';
        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int dec;
    cout << "ENTER THE NUMBER YOU WANT TO CONVERT TO BINARY : ";
    cin >> dec;
    cout << dec << " IN BINARY IS : " << convert(dec) << endl;
}