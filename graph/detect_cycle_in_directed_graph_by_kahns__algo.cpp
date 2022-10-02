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
bool Detect_Cycle_khans_algo(vector<int> adj[],int V,int indegree[])
{
    int count=0;
    queue<int>q;
    for(int i=0;i<V;i++)
        if(indegree[i]==0)
            q.push(i);
    while(q.empty()==false)
    {
        int v=q.front();
        q.pop();
        count++;
        for(auto u:adj[v])
        {
            if(--indegree[u]==0)
                q.push(u);
        }
    }
    if(count!=V)
        return true;
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
    int indegree[V];
    for(int i=0;i<V;i++)
        indegree[i]=0;

    for(int i=0;i<V;i++)
        for(auto x:adj[i])
            indegree[x]++;
    cout<<Detect_Cycle_khans_algo(adj,V,indegree);
}