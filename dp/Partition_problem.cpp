#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool subsetsum(int arr[],int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    if(arr[n-1]>sum)
    return subsetsum(arr,n-1,sum);

    return subsetsum(arr,n-1,sum)|| subsetsum(arr,n-1,sum-arr[n-1]);
}
int dp[1000][1000];
bool subset(int arr[],int n,int sum)
{
  if(sum==0)
  return true;
  if(n==0)
  return false;
    if(dp[n-1][sum]!=-1)
    {
        return dp[n-1][sum];
    }
    if(arr[n-1]>sum)
    dp[n-1][sum]=subset(arr,n-1,sum);
    else
    {
        return dp[n-1][sum]=subset(arr,n-1,sum) || subset(arr,n-1,sum-arr[n-1]);
    }
}
bool dpsubsetsum(int arr[],int n,int sum)
{
    bool set[n+1][sum+1];
    
    for(int i=0;i<sum+1;i++)
    set[0][i]=false;
     for(int i=0;i<n+1;i++)
    set[i][0]=true;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
          if(arr[i-1]>j)
          set[i][j]=set[i-1][j];
          if(j>=arr[i-1])
          set[i][j]=set[i-1][j]||set[i-1][j-arr[i-1]];
        }
    }
    return set[n][sum];
}
bool findpartition(int n,int arr[])
{
    int s=0;
    for(int i=0;i<n;i++) s+=arr[i];
    if(s%2)
    return false;
  return subsetsum(arr,n,s/2);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
memset(dp,-1,sizeof(dp));
  int arr[]={3,34,4,12,5,2};
  int n=6;
    if(findpartition(n,arr))
    cout<<"TRUE";
    else
    cout<<"FALSE";     
 return 0;
}