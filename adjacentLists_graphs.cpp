#include<iostream>
#include<list>
using namespace std;

class Graph
{
    public:
    list <int> *l;
    int n;

    Graph(int N)
    {
        l=new list <int> [N];
        n=N;
    }

    void addEdge(int u, int v, bool bidirec = true)
    {
        l[u].push_back(v);
        if (bidirec) l[v].push_back(u);
    }

    void printEdge()
    {
        for (int i=0; i<n; i++)
        {
            cout<<i<<":";

            for (auto child : l[i])
            {
                cout<<child<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,3);

    g.printEdge();
    
    return 0;
}