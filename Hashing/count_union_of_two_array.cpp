#include<bits/stdc++.h>
using namespace std;
int count_union(int a[],int b[],int n,int m)
{
    unordered_set<int>s1(a,a+n);
    s1.insert(b,b+m);
    // for(int i=0;i<m;i++)
    // {
    //     s1.insert(b[i]);
    // }
    return s1.size();
}
int main()
{
    int  n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    int *b=new int [m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    
    cout<<count_union(a,b,n,m);
}