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
bool isCycleBFS(vector<int> arr[],int v,int s)
{
    bool visited[v+1];
    for(int i=0;i<v+1;i++)
    {
        visited[i]=false;
    }
    vector<int> parent  (v,-1);
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        //cout<<u<<"  ";
        for(auto y:arr[u])
        {
            if(visited[y]==false)
            {
                visited[y]=true;
                q.push(y);
                parent[y]=u;
            }
            else if(parent[u]!=y)
                return true;
        }
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
    cout<<isCycleBFS(adj,V,0);
}