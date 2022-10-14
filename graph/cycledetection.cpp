#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <cstring>
#include <queue>
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
    // bfs khan's algo (topologiacl sorting)
    void tfs_bfs()
    {
        unordered_map<string, bool> visited;
        unordered_map<string, int> indegree;
        // calculate the indegree of every node
        for (auto p : adjList)
        {
            for (auto c : p.second)
            {
                indegree[c]++;
            }
        }
        // queue ke andr daalna h jinki indergree zero h
        queue<string> q;
        for (auto p : adjList)
        {
            if (indegree.count(p.first) == 0)
            {
                q.push(p.first);
                visited[p.first] = true;
            }
        }
        while (!q.empty())
        {
            string node = q.front();
            q.pop();
            cout << node << " ";
            for (auto c : adjList[node])
            {
                indegree[c]--;
                if (indegree[c] == 0)
                {
                    q.push(c);
                }
            }
        }
        cout << endl;
    }
    bool cycleBfs_helper(string node, unordered_map<string, bool> &visited, unordered_map<string, string> &parent)
    {
        queue<string> q;
        visited[node] = true;
        parent[node] = node;
        q.push(node);
        while (!q.empty())
        {
            string s = q.front();
            q.pop();
            for (auto c : adjList[s])
            {
                if (!visited[c])
                {
                    visited[c] = true;
                    parent[c] = s;
                    q.push(c);
                }
                else if (visited[c] and parent[s] != c)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool cycleBfs()
    {
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;
        for (auto p : adjList)
        {
            if (!visited[p.first])
            {
                if (cycleBfs_helper(p.first, visited, parent))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph g;
    // g.addEdge("English", "DSA");
    // g.addEdge("Laptop", "DSA");
    // g.addEdge("DSA", "Python");
    // g.addEdge("DSA", "Web");
    // g.addEdge("Python", "C++");
    // g.addEdge("Python", "ML");
    // g.addEdge("Web", "ML");
    // g.topologicalSort();

    g.addEdge("1", "0", true);
    // g.addEdge("2","0",true);
    g.addEdge("1", "3", true);
    g.addEdge("2", "3", true);
    // g.tfs_bfs();
    if (g.cycleBfs())
    {
        cout << "cycle hai\n";
    }
    else
    {
        cout << "cycle nhi hai\n";
    }
    return 0;
}