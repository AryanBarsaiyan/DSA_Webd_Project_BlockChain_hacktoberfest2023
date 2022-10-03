#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
void toposortbfs(int v,vector<int> adj[])
{
    //kahn algo
    queue<int> q;
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
    for(auto it:adj[i])
    indegree[it]++;
    }
    for(int i=0;i<v;i++)
    if(indegree[i]==0) q.push(i);

    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }

}
void find(int node,vector<int> adj[],stack<int> &st,vector<int> &vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            
            find(it,adj,st,vis);
        }
    }
    st.push(node);

}vector<int> topo;
void toposort(int v,vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(v,0);
    for(int i=0;i<v;i++)
    {
   if(vis[i]==0)
   find(i,adj,st,vis);
    } 
   
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();

    }
}  
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int v,e;
cin>>v>>e;
vector<int> adj[v];
for(int i=0;i<e;i++)
{
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
}
topo.empty();
toposort(v, adj);
for(int i=0;topo.size();i++)
cout<<topo[i]<<" ";
return 0;
}