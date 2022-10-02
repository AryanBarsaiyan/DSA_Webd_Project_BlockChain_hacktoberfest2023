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
void sort_distance(vector<int> adj[],int s,int v)
{
    queue<int>q;
    int dis[v];
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        dis[i]=-1;
        visited[i]=false;
    }
    dis[0]=0;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int p=q.front();
        q.pop();
        for(int x:adj[p])
        {
            if(visited[x]==false)
            {
                dis[x]=dis[p]+1;
                visited[x]=true;
                q.push(x);
            }
        }
    }
    for(int i=0;i<v;i++)
        cout<<dis[i]<<" ";
    
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