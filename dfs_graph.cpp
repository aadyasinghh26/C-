#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;

template <typename T>
class Graph
{
    public:
    map<T, list<T> > adj;

    void addEdge( T u, T v, bool bidirec=true)
    {
        adj[u].push_back(v);
        if (bidirec) adj[v].push_back(u);
    }

    void dfs_helper(T src, unordered_map<T, bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;

        for (auto child : adj[src])
        {
            if (!visited[child])
            {
                dfs_helper(child,visited);
            }
        }
    }

    void dfs(T src)
    {
        unordered_map<T, bool> visited;
        int component=1;
        dfs_helper(src,visited);

        for (auto p : adj)
        {
            if (!visited[p.first])
            {
                dfs_helper(p.first,visited);
                component++;
            }
        }
        cout<<"\nTotal components:"<<component<<endl;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(0,4);
    g.addEdge(6,7);
    g.addEdge(7,8);

    g.dfs(0);

    return 0;
}
