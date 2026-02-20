#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<cstring>
#include<queue>
using namespace std;

template <typename T>
class Graph
{
    public:
    map<T,list<T> > adj;

    void addEdge(T u, T v, bool bidirec=true)
    {
        adj[u].push_back(v);
        if (bidirec) adj[v].push_back(u);
    }

    void print()
    {
        for (auto p : adj)
        {
            cout<<p.first<<":";
            for (auto neighbours : p.second)
            {
                cout<<neighbours<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T src)
    {
        queue <T> q;
        unordered_map<T, bool> visited;

        q.push(src);
        visited[src]=true;

        while (!q.empty())
        {
            auto t=q.front();
            q.pop();
            cout<<t<<" ";

            for (auto child : adj[t])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
        cout<<endl;
    }

    void bfs_helper(T src, unordered_map<T, bool> &visited)
    {
        queue <T> q;

        q.push(src);
        visited[src]=true;

        while (!q.empty())
        {
            auto t=q.front();
            q.pop();
            cout<<t<<" ";

            for (auto child : adj[t])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
        cout<<endl;
    }

    void countComponent(T src)
    {
        int component=1;
        unordered_map<T, bool> visited;
        bfs_helper(src,visited);

        for (auto p : adj)
        {
            if (!visited[p.first])
            {
                bfs_helper(p.first,visited);
                component++;
            }
        }
        cout<<"Total components:"<<component<<endl;
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

    g.bfs(0);

    g.countComponent(0);

    return 0;
}
