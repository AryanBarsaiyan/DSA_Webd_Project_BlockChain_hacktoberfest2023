#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<pair<int,int>>adj[],int v,int u,int w )
{
    adj[v].push_back({u,w});
    adj[u].push_back({v,w});
}
void minimum_spaning_tree(vector<pair<int,int>> adj[],int V,int s)
{
    int sum=0;
    vector<int> v;
    bool isvisted[V];
    for(int i=0;i<V;i++)
        isvisted[i]=false;
    v.push_back(s);
    isvisted[s]=true;
    while(v.size()!=V)
    {   
        int min=INT_MAX,ver;
        bool flag=false;
        for(auto x:v)
        {
            for(auto u:adj[x])
            {
                if(isvisted[u.first]==false)
                {
                    if(u.second<min)
                    {
                        flag=true;
                        min=u.second;
                        ver=u.first;
                      //  cout<<min<<"B";
                    }
                }
            }
        }
        if(flag)
        {
           //cout<<min<<"A";
            sum+=min;
            v.push_back(ver);
            isvisted[ver]=true;
        }
    }
    cout<<sum<<endl;
}
int main()
{
    int V=4;
    vector<pair<int,int>> adj[V];
    add_edge(adj,0,1,5);
    add_edge(adj,0,2,8);
    add_edge(adj,1,2,10);
    add_edge(adj,2,3,20);
    add_edge(adj,1,3,15);
    minimum_spaning_tree(adj,V,0);

}