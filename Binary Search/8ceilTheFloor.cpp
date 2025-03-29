#include <bits/stdc++.h>
using namespace std;
int findFloor(vector<int> &a, int t)
{
    int ans = -1;
    int low = 0;
    int high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (a[mid] == t)
        {
            low = mid + 1;
            ans = mid;
        }
        else if (a[mid] < t)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    
}
int main()
{
    vector<int> a = {1, 2, 8, 10, 10, 12, 19};
    cout << findFloor(a, 11) << endl;
}