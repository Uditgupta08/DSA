#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *f = new int[len1];
    int *se = new int[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        f[i] = a[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        se[i] = a[k++];
    }
    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2)
    {
        if (f[index1] < se[index2])
        {
            a[k++] = f[index1++];
        }
        else
        {
            a[k++] = se[index2++];
        }
    }
    while (index1 < len1)
    {
        a[k++] = f[index1++];
    }
    while (index2 < len2)
    {

        a[k++] = se[index2++];
    }
}
void mergeSort(vector<int> &a, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
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
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}