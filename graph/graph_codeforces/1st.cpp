#include<bits/stdc++.h>
using namespace std;
void dfs(int src,vector<int> adj[],vector<int>&visited)
{
    visited[src]=1;
    cout<<src<<" s";
    for(auto x:adj[src])
        if(!visited[x])
            dfs(x,adj,visited);
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];
    //vector<vector><int>adj(v+1);
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(int i=1;i<=v;i++)
    // {
    //     cout<<i<<"->";
    //     for(auto x:adj[i])
    //         cout<<x<<" ";
    //     cout<<endl;
    // }
    // for(int i=1;i<=v;i++)
    // {
    //     cout<<i<<"->";
    //     for(int j=1;j<adj[i].size();j++)
    //         cout<<adj[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int>visied;
    for(int i=1;i<=v;i++)
        visied[i]=0;
    dfs(1,adj,visied);

}