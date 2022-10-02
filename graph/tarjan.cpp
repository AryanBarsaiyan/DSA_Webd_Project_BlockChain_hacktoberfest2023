#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define all(x)      (x).begin(), (x).end()
#define inp(x) for(ll&i:x) cin>>i;
#define f(i,x,n) for(ll i=x;i<n;i++)
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
ll mypow(ll a, ll b) {
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a;
a = a * a;
b >>= 1;
}
return res;
}
ll mypow(ll a, ll b, ll m) {
a %= m;
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;
   vector<vector<int>>ans;

void dfs(int node,vector<int>adj[],vector<int>&itime,
vector<int>&low,vector<bool>&visited,int &timer,stack<int>&s,
vector<bool>&stack_presence){
    itime[node]=low[node]=timer++;
    visited[node]=true;
    s.push(node);
    stack_presence[node]=true;
    
    for(int x:adj[node]){
        if(visited[x]==false){
            dfs(x,adj,itime,low,visited,timer,s,stack_presence);
            low[node]=min(low[node],low[x]);
        }
        //checking crossedge
        else{
            if(stack_presence[x]==true)
            low[node]=min(low[node],itime[x]);
        }
    }
    if(itime[node]==low[node]){
        vector<int>v;
        while(s.top()!=node){
            int val=s.top();
            s.pop();
            stack_presence[val]=false;
            v.push_back(val);
        }
        v.push_back(s.top());
        s.pop();
        stack_presence[node]=false;
        sort(v.begin(),v.end());
        ans.push_back(v);
    }
}
  vector<vector<int>> tarjans(int V, vector<int> adj[])
   {
       ans.clear();
       //code here
       vector<int>itime(V,-1);
       vector<int>low(V,-1);
       vector<bool>visited(V,false);
       int timer=0;
       stack<int>s;
       vector<bool>stack_presence(V,false);
       for(int i=0;i<V;i++){
           if(visited[i]==false)
           dfs(i,adj,itime,low,visited,timer,s,stack_presence);
       }
       sort(ans.begin(),ans.end());
       return ans;
   }

int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
 ll n,e;
  cin>>n>>e;
  vector<int> adj[n+1];
  for(int i=0;i<e;i++)
  {
      int a,b;
      cin>>a>>b;
      adj[a].pb(b);
  
  }
  vector<vector<int>> res=tarjans(n,adj);
  cout<<"SCC is:\n";
  for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
    {
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
return 0;
}