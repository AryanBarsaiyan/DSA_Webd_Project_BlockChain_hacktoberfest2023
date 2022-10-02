#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[],int v,int u )
{
    adj[v].push_back(u);
}
void DFS(vector<int> adj[],int s,bool isvisted[],stack<int> &st)
{
    isvisted[s]=true;
    for(auto u:adj[s])
    {
        if(isvisted[u]==false)
            DFS(adj,u,isvisted,st);
    }
    st.push(s);
}
void topo_sort_DFS(vector<int>adj[],int V)
{
    bool isvisted[V];
    for(int i=0;i<V;i++)
        isvisted[i]=false;
    stack<int> st;
    for(int i=0;i<V;i++)
    {
        if(isvisted[i]==false)
            DFS(adj,i,isvisted,st);
    }
    while(st.empty()==false)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    int V=5;
    vector<int> adj[V];
    add_edge(adj,0,1);
    add_edge(adj,1,3);
    add_edge(adj,3,4);
    add_edge(adj,2,3);
    add_edge(adj,2,4);
    topo_sort_DFS(adj,V);

}