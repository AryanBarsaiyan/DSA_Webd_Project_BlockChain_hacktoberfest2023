#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<pair<int,int>>adj[],int v,int u,int w )
{
    adj[v].push_back({u,w});
    adj[u].push_back({v,w});
}
vector<int> dijkstra_algo(vector<pair<int,int>> adj[],int V,int s)
{
    vector<int> dist;
    bool fin[V];
    for(int i=0;i<V;i++)
    {
        dist.push_back(INT_MAX);
        fin[i]=false;
    }
    dist[s]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=-1;
        for(int i=0;i<V;i++)
        {
            if(!fin[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        }
        fin[u]=true;
        for(auto v:adj[u])
        {
            if(fin[v.first]==false)
                dist[v.first]=min(dist[v.first],(dist[u]+v.second));
        }
    }
    return dist;
}
int main()
{
    int V=4;
    vector<pair<int,int>> adj[V];
    add_edge(adj,0,1,50);
    add_edge(adj,0,2,100);
    add_edge(adj,1,2,30);
    add_edge(adj,2,3,20);
    add_edge(adj,1,3,200);
    vector<int> dist=dijkstra_algo(adj,V,0);
    for(auto x:dist)
        cout<<x<<"  ";

}