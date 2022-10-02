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
void print_topological_sorting(vector<int> adj[],int V,int indegree[])          //only for acyclic graphss
{
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(q.empty()==false)
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto u:adj[x])
        {
            if(--indegree[u]==0)
                q.push(u);
        }
    }
}
int main()
{
    int V=5;
    vector<int> adj[V];
    addEdged(adj,0,2);
    addEdged(adj,0,3);
    addEdged(adj,1,3);
    addEdged(adj,1,4);
    addEdged(adj,2,3);
    int indegree[V];
    for(int i=0;i<V;i++)
        indegree[i]=0;

    for(int i=0;i<V;i++)
        for(auto x:adj[i])
            indegree[x]++;
    print_topological_sorting(adj,V,indegree);
}