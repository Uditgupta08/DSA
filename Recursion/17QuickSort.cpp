#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &a, int s, int e)
{
    int pivot = a[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (a[i] <= pivot)
        {
            count++;
        }
    }
    int ind = s + count;
    swap(a[ind], a[s]);
    int i = s;
    int j = e;
    while (i<ind & j> ind)
    {
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<ind && j > ind){
            swap(a[i++],a[j--]);
        }
    }
    return ind;
}
void quickSort(vector<int> &a, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS : ";
    cin >> n;
    vector<int> a(n);
    cout << "ENTER THE ELEMENTS : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}