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
void dfs(vector<int> adj[],vector<int> &vis,int cur,stack<int> &st)
{
    vis[cur]=1;
    for(auto it:adj[cur])
    {  if(!vis[it])
        dfs(adj,vis,it,st);
    }
    st.push(cur);
} 
void revdfs(int cur,vector<int> &vis,vector<int> transpose[])
{
    cout<<cur<<" ";
    vis[cur]=1;
    for(auto it:transpose[cur])
    {
        if(!vis[it])
        revdfs(it,vis,transpose);
    }
}
int main()
{
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
  // step 1 to do the toposort

stack<int> st;
vector<int> vis(n+1,0);
for(int i=0;i<n;i++)
{
    if(!vis[i])
    dfs(adj,vis,i,st);
}
 vis=vector<int>(n+1,0); // again unvisit whole vector
vector<int> transpose[n+1];
for(int i=0;i<n;i++)
{
    for(auto it:adj[i])
    transpose[it].push_back(i);
}
while(!st.empty())
{
    int node=st.top();
    st.pop();
    if(!vis[node])
    {
        cout<<"Scc:";
        revdfs(node,vis,transpose);
        cout<<endl;
    }
}
}
return 0;
}