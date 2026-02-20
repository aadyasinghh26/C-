#include<iostream>
#include<unordered_map>
#include<map>     //data will be printed in sorted order
#include<list>
#include <cstring>
using namespace std;

class Graph
{
    public:
    map<string, list<string> > adj;

    void addEdge(string u, string v, bool bidirec = true)
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
};

int main()
{
    Graph g;
    g.addEdge("A","B");
    g.addEdge("D","B");
    g.addEdge("D","C");
    g.addEdge("D","E");
    g.addEdge("A","C");
    g.addEdge("A","D");

    g.print();

    return 0;
}
