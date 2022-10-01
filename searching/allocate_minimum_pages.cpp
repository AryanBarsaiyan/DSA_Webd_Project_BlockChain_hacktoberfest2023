#include<bits/stdc++.h>
using namespace std;
int sum(int arr[],int a,int b)
{
    int sum=0;
    for(a;a<=b;a++)
        sum+=arr[a];
    return sum;
}
int naieve_approch(int arr[],int n,int k)
{
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    res=min(res,max(naieve_approch(arr,i,k-1),sum(arr,i,n-1)));
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
    cout<<naieve_approch(a,n,k);
}