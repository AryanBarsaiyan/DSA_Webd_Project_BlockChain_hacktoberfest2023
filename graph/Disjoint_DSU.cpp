#include<bits/stdc++.h>
using namespace std;
#define pb push_back()
vector<int> parent(1000);
vector<int> Rank(1000);
int n=7;
void makeset()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        Rank[i]=0;
    }    
}
int findparent(int node)
{
    if(node==parent[node]) return node;
    return parent[node]=findparent(parent[node]);
}
void Union(int u,int v)
{
  u=findparent(u);
  v=findparent(v);
  if(Rank[u]<Rank[v])
  parent[u]=v;
  else if(Rank[u]>Rank[v])
  parent[v]=u;
  else
  {
      parent[v]=u;
      Rank[u]++;
  }
}

int main()
{  makeset();
    int t;
cin>>t;
while(t--)
{
  int u,v;
  cin>>u>>v;
  Union(u,v);
}
if(findparent(2)==findparent(4))
cout<<"Same\n";
e+
lse
cout<<"Different\n";
    return 0;
}