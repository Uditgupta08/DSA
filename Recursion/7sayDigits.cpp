#include <bits/stdc++.h>
using namespace std;
string sayDigit(int n, vector<string> a)
{
    string ans = "";
    if (n == 0)
    {
        return ans;
    }
    int i = n % 10;
    return sayDigit(n / 10, a) + (a[i] + " ");
}
int main()
{
    vector<string> a = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine"};
    int n;
    cout << "ENTER THE NUMBER : ";
    cin >> n;
    if(n == 0){
        cout<<a[0]<<endl;
    }
    cout << sayDigit(n, a);
}