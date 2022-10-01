#include<bits/stdc++.h>
using namespace std;
void count(int a[],int n,int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[a[i]]++;
    // for(auto at=m.begin();at!=m.end();at++)
    // {
    //     if((*at).second>n/k)
    //         cout<<(*at).first<<"   ";
    // }
    for(auto e:m)
    {
        if(e.second>n/k)
            cout<<e.first<<"  ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    count(a,n,k);
}
