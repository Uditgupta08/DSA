#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cout<<"ENTER THE NUMBER YOU WANT TO CHECK : ";
    cin>>a;
    if((a&(a-1))==0){
        cout<<"POWER OF 2"<<endl;
    }
    else{
        cout<<"NOT POWER OF 2"<<endl;
    }
}