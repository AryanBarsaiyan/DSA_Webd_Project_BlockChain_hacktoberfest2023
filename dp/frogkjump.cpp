                                                                    //tabulation soln  1

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
// power with modulo N;
int powersmodulo(int a, int b)
{
    if (b == 0)
        return 1;
    int res = powersmodulo(a, b / 2);
    if (b & 1)
        return (res % MOD * res % MOD * a % MOD) % MOD;
    else
        return (res % MOD * res % MOD) % MOD;
}
void solve()
{
    int n,k;    cin>>n>>k;
    vector<int> cost(n,0);
    for(auto &i:cost) cin>>i;
    vector<int> dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int min_cost=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int x=dp[i-j]+abs(cost[i]-cost[i-j]);
                if(x<min_cost)
                    min_cost=x;
            }
        }
        dp[i]=min_cost;
    }
    cout<<dp[n-1]<<endl;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}







                                                            // soln 2 momoization


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define MOD 1000000007
// // power with modulo N;
// int powersmodulo(int a, int b)
// {
//     if (b == 0)
//         return 1;
//     int res = powersmodulo(a, b / 2);
//     if (b & 1)
//         return (res % MOD * res % MOD * a % MOD) % MOD;
//     else
//         return (res % MOD * res % MOD) % MOD;
// }
// int solvedp(vector<int>&cost,vector<int>&dp,int n,int k)
// {
//     if(n==0)
//         return 0;
//     if(dp[n]!=-1)
//         return dp[n];
//     int ans=INT_MAX;
//     for(int i=1;i<=k;i++)
//     {
//         if(n-i>=0)
//             ans=min(ans,solvedp(cost,dp,n-i,k)+abs(cost[n]-cost[n-i]));
//     }
//     dp[n]=ans;
//     return dp[n];

// }
// void solve()
// {
//     int n,k;    cin>>n>>k;
//     vector<int> cost(n,0);
//     for(auto &i:cost) cin>>i;
//     vector<int> dp(n+1,-1);
//     cout<<solvedp(cost,dp,n-1,k)<<endl;
// }
// int32_t main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif  
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t=1;
//     // cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }