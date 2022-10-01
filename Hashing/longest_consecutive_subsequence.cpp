#include<bits/stdc++.h>
using namespace std;
int result(int a[],int n)
{
    unordered_set<int>s(a,a+n);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int count=1;
        if(s.find(a[i]-1)!=s.end())
            count=1;
        else
        {
            while(s.find(a[i]+count)!=s.end())
                count++;
        }
        res=max(res,count);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<result(a,n)<<endl;
}