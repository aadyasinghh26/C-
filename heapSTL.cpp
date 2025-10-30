#include<iostream>
#include<queue>
using namespace std;

class comparator
{
    public:

    bool operator() (int a, int b)
    {
        return a>b;
    }
};

int main()
{
    priority_queue<int> h;          //max heap
    //priority_queue<int, vector<int>, comparator> h;     //max heap  a>b and min heap a<b
    //priority_queue<int, vector<int>, greater<int> >h;    //min heap
    //priority_queue<int, vector<int>, less<int> >h;         //max heap

    h.push(1);
    h.push(4);
    h.push(2);
    h.push(3);
    h.push(0);

    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;

    return 0;
}