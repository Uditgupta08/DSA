#include <iostream>
#include <string>
using namespace std;
int convert(string bin)
{
    int n = bin.length();
    int ans = 0;
    int p = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            ans += p;
        }
        p = p * 2;
    }
    return ans;
}
int main()
{
    string bin;
    cout << "ENTER THE BINARY NUMBER : ";
    cin >> bin;
    int ans = convert(bin);
    cout << bin << " IN DECIMAL IS : " << ans << endl;
    return 0;
}