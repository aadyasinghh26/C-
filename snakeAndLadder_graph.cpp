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
    map <T, list<T> >adj;

    void addEdge(T u, T v, bool bidirec=false)
    {
        adj[u].push_back(v);
        if (bidirec) adj[v].push_back(u);
    }

    int SSSP(T src, T des)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;
        unordered_map<T, T> parent;

        q.push(src);
        visited[src]=true;
        distance[src]=0;
        parent[src]=src;

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

        //printing the path

        T des_copy=des;
        while (des!=src)
        {
            cout<<des<<"<--";
            des=parent[des];
        }
        cout<<des<<endl;
        return distance[des_copy];
    }
};

int main()
{
    Graph <int> g;

    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;

    for (int u=0;u<=36;u++)
    {
        for (int dice=1;dice<=6;dice++)
        {
            int v=u + dice;
            v+=board[v];
            g.addEdge(u,v,false);   //Adds edges for every dice move
        }
    }

    int ans=g.SSSP(0,36);
    cout<<"Distance:"<<ans<<endl;

    return 0;
}