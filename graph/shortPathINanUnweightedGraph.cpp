#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++) {   
        for (auto x : adj[i])
            cout <<x;
        cout<<endl;
    }
}
void sort_distance(vector<int> adj[],int s,int V)
{
    vector<bool> isvisted(V,false);
    vector<int> dist(V,INT_MAX);
    queue<int> q;
    q.push(s);
    isvisted[s]=true;
    dist[s]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto u:adj[v])
        {
            if(!isvisted[u])
            {
                dist[u]=dist[v]+1;
                isvisted[u]=true;
                q.push(u);
            }
        }

    }
    for(auto x:dist)
        cout<<x<<" ";
    
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    //addEdge(adj, 3, 4);
    // printGraph(adj, V);
    //  cout<<endl;
    sort_distance(adj,0,V);
    return 0;
}