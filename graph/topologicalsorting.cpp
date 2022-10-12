#include <iostream>
#include <map>
#include <list>
#include<cstring>
using namespace std;
class graph
{
public:
    map<string, list<string>> adjList;
    void addEdge(string u, string v, bool bidir = false)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void helper(map<string, bool> &visited, string node, list<string> &l)
    {
        visited[node] = true;
        for (auto child : adjList[node])
        {
            if (!visited[child])
            {
                helper(visited, child, l);
            }
        }
        l.push_front(node);
    }
    void topologicalSort()
    {
        list<string> l;
        map<string, bool> visited;
        for (auto p : adjList)
        {
            if (!visited[p.first])
            {
                helper(visited, p.first, l);
            }
        }
        for (auto e : l)
        {
            cout << e << " ";
        }
        cout << endl;
    }
};
int main()
{
    graph g;
    g.addEdge("English", "DSA");
    g.addEdge("Laptop", "DSA");
    g.addEdge("DSA", "Python");
    g.addEdge("DSA", "Web");
    g.addEdge("Python", "C++");
    g.addEdge("Python", "ML");
    g.addEdge("Web", "ML");
    g.topologicalSort();
    return 0;
}