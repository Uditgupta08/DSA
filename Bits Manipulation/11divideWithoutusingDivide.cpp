#include <bits/stdc++.h>
using namespace std;
int solve(int d, int b)
{
    if (d == INT_MAX && b == -1)
    {
        return INT_MIN + 1;
    }
    if (d == INT_MIN && b == -1)
    {
        return INT_MAX;
    }
    if (d == b)
    {
        return 1;
    }
    bool sign = true;
    if (d >= 0 && b < 0)
        sign = false;
    if (b > 0 && d <= 0)
        sign = false;
    long long n = abs(d);
    long long a = abs(b);
    long ans = 0;
    while (n >= a)
    {
        int count = 0;
        while (n >= (a << (count + 1)))
        {
            count++;
        }
        ans += (1 << count);
        n = n - (a << count);
    }
    if (ans >= INT_MAX && sign == true)
    {
        return INT_MAX;
    }
    if (ans >= INT_MAX && sign == false)
    {
        return INT_MIN;
    }
    return sign ? ans : (-1 * ans);
}
int main()
{
    int n, a;
    cout << "ENTER DIVIDENT AND DIVISIOR : ";
    cin >> n >> a;
    cout << solve(n, a) << endl;
}