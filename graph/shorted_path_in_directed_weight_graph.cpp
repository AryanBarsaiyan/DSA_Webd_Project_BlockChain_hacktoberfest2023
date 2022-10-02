#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<pair<int,int>>adj[],int v,int u,int w )
{
    adj[v].push_back({u,w});
}
void DFS(vector<pair<int,int>> adj[],int s,bool isvisted[],stack<int> &st)
{
    isvisted[s]=true;
    for(auto u:adj[s])
    {
        if(isvisted[u.first]==false)
            DFS(adj,u.first,isvisted,st);
    }
    st.push(s);
}
vector<int> topo_sort_DFS(vector<pair<int,int>>adj[],int V)
{
    vector<int>v;
    bool isvisted[V];
    for(int i=0;i<V;i++)
        isvisted[i]=false;
    stack<int> st;
    for(int i=0;i<V;i++)                                            
    {
        if(isvisted[i]==false)
            DFS(adj,i,isvisted,st);
    }
    while(st.empty()==false)
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}
void sortest_path(vector<pair<int,int>> adj[],vector<int> new_adj,int V,int s)
{
    int dist[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[s]=0;
    for(auto x:new_adj)
    {
        // cout<<"a";
        for(auto y:adj[x])
        {
            int a=y.first,b=y.second;               //b is weight(u,v) a is dist[v] and   dist[x] is dist[u]
            if(dist[a]>(b+dist[x]))
                dist[a]=b+dist[x];
        }
    }
    for(int i=0;i<V;i++)
        cout<<dist[i]<<"  ";
}
int main()
{
    int V=6;
    vector<pair<int,int>> adj[V];
    add_edge(adj,0,1,2);
    add_edge(adj,0,4,1);
    add_edge(adj,1,2,3);
    add_edge(adj,2,3,6);
    add_edge(adj,4,2,2);
    add_edge(adj,4,5,4);
    add_edge(adj,5,3,1);
    vector<int> new_adj=topo_sort_DFS(adj,V);
    // for(auto x:new_adj)
    //     cout<<x<<"  ";
    sortest_path(adj,new_adj,V,0);
    

}