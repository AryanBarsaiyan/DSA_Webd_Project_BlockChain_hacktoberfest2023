#include<bits/stdc++.h>
using namespace std;
int count_intersection(int a[],int b[],int n,int m)
{
    unordered_set<int>s1(a,a+n);
    int res=0;
    for(int i=0;i<m;i++)
    {
        if(s1.find(b[i])!=s1.end())
        {
            res++;
            s1.erase(b[i]);
        }
    }
    return res;
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
    
    cout<<count_intersection(a,b,n,m);
}