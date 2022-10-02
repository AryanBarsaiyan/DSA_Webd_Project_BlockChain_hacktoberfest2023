#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
        
    void fill_order(int v,bool isvisted[],stack<int> &st)
    {
        isvisted[v]=true;
        for(auto x:adj[v])
        {
            if(!isvisted[x])
                fill_order(x,isvisted,st);
        }
        st.push(v);
    }
    void DFS_print(int v,bool isvisted[])
    {
        isvisted[v]=true;
        cout<<v<<" ";
        for(auto x:adj[v])
            if(!isvisted[x])
                DFS_print(x,isvisted);
    }
    public:

        Graph(int V)
        {
            this->V=V;
            adj=new list<int>[V];
        }
        void addEdge(int v,int w)
        {
            adj[v].push_back(w);
        }

        void printSCCs();

        Graph getTranspose()
        {
            Graph g(V);
            for(int i=0;i<V;i++)
            for(auto x:adj[i])
            {
                g.addEdge(x,i);
            }
            return g;
        }

};
// Graph Graph::getTranspose()
// {
//     Graph g(V);
//     for(int i=0;i<V;i++)
//         for(auto x:adj[i])
//         {
//             g.addEdge(x,i);
//         }
//     return g;
// }
void Graph::printSCCs()
{
    stack<int> st;
    bool isvisted[V];
    for(int i=0;i<V;i++)
        isvisted[i]=false;
    
    for(int i=0;i<V;i++)
        if(!isvisted[i])
            fill_order(i,isvisted,st);
    
    Graph gr = getTranspose();
    for(int i=0;i<V;i++)
        isvisted[i]=false;
    
    while(!st.empty())
    {
        int v=st.top();
        st.pop();
        if(!isvisted[v])
        {
            gr.DFS_print(v,isvisted);
            cout<<endl;
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
  
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
  
    return 0;
}