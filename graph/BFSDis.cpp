#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
// void printGraph(vector<int> adj[], int V)
// {
//     for (int i = 0; i < V; i++) {   
//         for (auto x : adj[i])
//             cout <<x;
//         cout<<endl;
//     }
// }
void BFS(vector<int> arr[],int s,bool visited[])
{
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<"  ";
        for(int y:arr[u])
        {
            if(visited[y]==false)
            {
                visited[y]=true;
                q.push(y);
            }
        }
    }
}
void BFSD(vector<int> arr[],int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            BFS(arr,i,visited);
    }
}
int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    
    //printGraph(adj, V);
    BFSD(adj,V);
    return 0;
}