#include<bits/stdc++.h>
using namespace std;
int longest_sub_array(int temp[],int n,int sum){
    unordered_map<int,int>m; 
    int pre_sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=temp[i];
        if(m.find(pre_sum-sum)!=m.end())
        {
            res=max(res,i-m[pre_sum-sum]);
        }
        if(pre_sum==sum)
            res=i+1;
        m.insert({pre_sum,i});
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],temp[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        temp[i]=a[i]-b[i];
    cout<<longest_sub_array(temp,n,0);
}