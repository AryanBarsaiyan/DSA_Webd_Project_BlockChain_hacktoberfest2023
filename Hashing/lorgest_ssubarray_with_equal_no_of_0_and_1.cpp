#include<bits/stdc++.h>                         //binary array
using namespace std;
int result(int a[],int n,int sum)
{
    unordered_map<int,int> h;
    int pre_sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {                                                       //method 2:if a[i]=0 then replace with -1
        if(a[i]!=0)
        pre_sum+=a[i];
        else
            pre_sum--;
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
{                                                               // Method 1: we we allowed to modify the array then replace 0 with -1 then queestion become lorgest subarray with 0 sum
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)                                                        
        cin>>a[i];
    cout<<result(a,n,0);
}