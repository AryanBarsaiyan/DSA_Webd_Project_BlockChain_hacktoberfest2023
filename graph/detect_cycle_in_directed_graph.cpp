#include<bits/stdc++.h>
using namespace std;
void addEdged(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
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
bool  rec_DFS_cycle(vector<int>adj[],int s,bool visited[],bool recstack[])
{
    visited[s]=true;
    recstack[s]=true;
    for(auto x:adj[s])
    {
        if(visited[x]==false && rec_DFS_cycle(adj,x,visited,recstack))
            return true;
        else if(recstack[x]==true)
            return true; 
    }
    recstack[s]=false;
    return false;
}
bool detect_cycle_DFS(vector<int>adj[],int V)
{
    bool visited[V];
    bool recstack[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        recstack[i]=false;
    }
    for(int i=0;i<V;i++)
    {
       if(visited[i]==false)
            if(rec_DFS_cycle(adj,i,visited,recstack)==true)
                return true;
    }
    return false;
}
int main()
{
    int V=6;
    vector<int> adj[V];
    addEdged(adj,0,1);
    addEdged(adj,2,1);
    addEdged(adj,2,3);
    addEdged(adj,3,4);
    addEdged(adj,4,5);
    addEdged(adj,5,3);
    //printGraph(adj,V);
    cout<<detect_cycle_DFS(adj,V);
}