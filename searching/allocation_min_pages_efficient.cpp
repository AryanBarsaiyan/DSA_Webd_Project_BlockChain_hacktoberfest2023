#include<bits/stdc++.h>
using namespace std;
bool isfeasible(int arr[],int n,int k,int ans)
{
    int res=1,sum=0;
    for(int i=0;i<n;i++)
        if(sum+arr[i]>ans)
        {
            res++;
            sum=arr[i];
        }
        else
        {
            sum+=arr[i];
        }
        return (res<=k);
}
int ans(int arr[],int n,int k)
{
    int sum=0,mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        mx=max(mx,arr[i]);
    }
    int low=mx,high=sum,res=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isfeasible(arr,n,k,mid))
        {
            res=mid;                        //  if feasible , go to  
            high=mid-1;                     //  the left half
        }
        else
            low=mid+1;                      //  else go to the right half
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
    int k;
    cin>>k;
    cout<<ans(a,n,k);
}