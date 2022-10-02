#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<pair<int,int>> *adj;
    
    public:

        Graph(int V)
        {
            this->V=V;
            adj=new list<pair<int,int>>[V];
        }
        void addEdge(int v,int u,int w)
        {
            adj[v].push_back({u,w});
        }
        void Bellman_ford(int src)
        {
            int dist[V];
            for(int i=0;i<V;i++)
                dist[i]=INT_MAX;
            dist[src]=0;
            for(int count=0;count<V-1;count++)
            {

                                //there two for loop run E times so time complexity is O(V*E);

                for(int i=0;i<V;i++)
                {
                    for(auto x:adj[i])
                    {
                        dist[x.first]=min(dist[x.first],dist[i]+x.second);
                    }
                }
            }
            for(int i=0;i<V;i++)
            {
                for(auto x:adj[i])
                {
                    if(dist[x.first] !=INT_MAX && dist[i]+x.second <dist[x.first])
                    {
                        cout<<"Graph contain negative cycle"<<endl;
                        return ;
                    }
                }
            }
            cout<<"Vertex   Distance from Source\n";
            for (int i = 0; i < V; ++i)
                cout<<dist[i]<<" ";
            return ;

        }
        

};


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,2,-3);
    g.addEdge(1,3,2);
    g.addEdge(0,2,4);
    g.addEdge(2,3,3);
    
    g.Bellman_ford(0);
  
    
  
    return 0;
}