#include<bits/stdc++.h>
using namespace std;
class DSU
{
    int *rank;
    int *parent;
    public:
        DSU(int n)
        {
            rank=new int[n];
            parent=new int[n];
            for(int i=0;i<n;i++)
            {
                rank[i]=1;
                parent[i]=i;
            }
        }

        int find(int i)
        {
            if(parent[i]==i)
                return i;
            return parent[i]=find(parent[i]);
        }

        void Union(int x,int y)
        {
            int s1=find(x);
            int s2=find(y);
            if(s1!=s2)
            {
                if(rank[s1]<rank[s2])
                {
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else
                {
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};
class Graph
{
    vector<vector<int>> edgelist;
    int V;
    public:
        Graph(int v)
        {    
            V=v;
        }
        void addEdge(int v,int u,int w)
        {
            edgelist.push_back({w,v,u});
        }
        void kruskals()
        {
            sort(edgelist.begin(),edgelist.end());
            DSU s(V);
            int ans=0;

            for(auto edge:edgelist)
            {
                int w=edge[0];
                int v=edge[1];
                int u=edge[2];
               // cout<<w<<" "<<v<<" "<<u<<endl;
                if(s.find(v)!=s.find(u))
                {
                    s.Union(v,u);
                    ans+=w;
//                    cout << v << " -- " << u << " == " << w
//					<< endl;
                }
            }
            cout<<"Minimum Cost Of Spanning Tree = "<<ans;
        }    
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 	
    g.kruskals();
    return 0;
}