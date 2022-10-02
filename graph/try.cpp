#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vpll vector<pair<ll, ll>>
#define pll pair<ll, ll>;
#define MX INT_MAX
#define MN INT_MIN
#define MOD 1e9 + 9
using namespace std;
    
ll powers(ll a, ll b){
    if(b==0)
    return 1;
    ll res = powers(a,b/2);
    if(b&1)
    return res*res*a;
    else
    return res*res;
}
    
//power with modulo N;
ll powersmodulo(ll a, ll b ,ll N){
    if(b==0)
    return 1;
    ll res = powersmodulo(a,b/2,N);
    if(b&1)
    return (res%N*res%N*a%N)%N;
    else
    return (res%N*res%N)%N;
}
    
void solve(){
//check t
    
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}