#include<iostream>
#include<list>
#include<map>
#include<unordered_map>
#include<queue>
#include<cstring>
using namespace std;

template<typename T>
class Graph
{
    public:
    unordered_map<T, list<pair<T, int> > > adj;

    void addEdge(T u, T v, int d, bool bidirec=true)
    {
        adj[u].push_back({v,d});
        if (bidirec) adj[v].push_back({u,d});
    }

    void print()
    {
        for (auto p : adj)
        {
            cout<<p.first<<":";
            for (auto item : p.second)
            {
                cout<<"("<<item.first<<","<<item.second<<")";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph <char> g;

    g.addEdge('A','B',1);
    g.addEdge('C','B',2);
    g.addEdge('C','A',5);
    g.addEdge('D','A',8);
    g.addEdge('D','C',3);

    g.print();

    return 0;
}