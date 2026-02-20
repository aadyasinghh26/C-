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
    map<T, list<T> > adj;

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
            for (auto neighbour : p.second)
            {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    int SSSP(T src, T des)   //SINGLE SOURCE SHORTEST PATH
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;
        unordered_map<T, T> parent;

        q.push(src);
        visited[src]=true;
        parent[src]=src;
        distance[src]=0;

        while (!q.empty())
        {
            auto t=q.front();
            q.pop();

            for (auto child : adj[t])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child]=true;
                    parent[child]=t;
                    distance[child]=distance[t]+1;
                }
            }
        }

        //printing the shortest path
        //destination se shuru karo and parent tak jaate raho

        T des_copy=des;  //Because in the loop below you will modify des while moving upward.
                         //But at the end you still need the original destination to return distance.
                         //So this is just a backup
                         
        while (des != src)
        {
            cout<<des<<"<--";
            des=parent[des];
        }
        cout<<des<<endl;   //loop stops
                           //des==src
                           //prints the source node at the end
        return distance[des_copy];
    }
};

int main()
{
    Graph <int> g;
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(0,4);

    g.print();

    cout<<"Distance:"<<g.SSSP(0,5)<<endl;

    return 0;
}