#include<bits/stdc++.h>
using namespace std;
int result(int a[],int n,int sum)
{
    unordered_map<int,int> h;
    int pre_sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=a[i];
        if(h.find(pre_sum-sum)!=h.end())
        {
            res=max(res,i-h[pre_sum -sum]);
        }
        if(pre_sum==sum)
            res=i+1;
        h.insert({pre_sum,i});
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
    int sum;
    cin>>sum;
    cout<<result(a,n,sum);
}