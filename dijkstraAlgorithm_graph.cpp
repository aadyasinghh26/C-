#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<set>
#include<cstring>
#include<climits>
using namespace std;

template <typename T>
class Graph
{
    public:
    map<int, list<pair<int, T> > > adj;

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

    int dijkstra(T src, T des)
    {
        set<pair<int, T> > s;
        unordered_map<T, T> parent;
        unordered_map<T, int> distance;

        for (auto p : adj)
        {
            distance[p.first]=INT_MAX;
        }

        parent[src]=src;
        distance[src]=0;
        s.insert({0,src});

        while (!s.empty())
        {
            auto x=*(s.begin());
            s.erase(s.begin());

            int d=x.first;
            T t=x.second;

            for (auto p : adj[t])
            {
                auto ch=p.first;
                int edge_d=p.second;

                if (distance[ch] > d + edge_d)
                {
                    auto f=s.find({distance[ch],ch});
                    if (f != s.end()) s.erase(f);

                    s.insert({d+edge_d,ch});
                    parent[ch]=t;
                    distance[ch]=d+edge_d;
                }
            }
        }

        T des_copy=des;
        while(des != src)
        {
            cout<<des<<"<--";
            des=parent[des];
        }
        cout<<des<<endl;
        return (distance[des_copy]);
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

    int ans=g.dijkstra('A','D');
    cout<<ans;

    return 0;
}