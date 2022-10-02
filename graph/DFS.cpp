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
void DFSRec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int x: adj[s])
        if(visited[x]==false)
            DFSRec(adj,x,visited);
}
void DFS(vector<int> adj[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[v]=false;
    for(int i=0;i<v;i++)
        if(visited[i]==false)
            DFSRec(adj,s,visited);
}
int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    printGraph(adj, V);
     cout<<endl;
    DFS(adj,V,0);
    return 0;
}