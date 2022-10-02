#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// void printGraph(vector<int> adj[],int V)
// {
//     for(int i=0;i<V;i++)
//     {
//         for(auto x:adj[i])
//             cout<<x<<" ";
//         cout<<endl;
//     }
// }
bool DFSrec(vector<int> adj[],int s,bool visited[],int parent)
{
    visited[s]=true;
    for(int x: adj[s])
    {
        if(visited[x]==false){
            if(DFSrec(adj,x,visited,s)==true)
                return true;
        }
        else if(x!=parent)
            return true;
    }
    return false;
}
bool detec_cycle_DFS(vector<int> adj[],int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            if(DFSrec(adj,i,visited,-1)==true)
                return true;
    }
    return false;
}
int main()
{
    int V=6;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    //printGraph(adj,V);
    cout<<detec_cycle_DFS(adj,V);
}