#include<iostream>
#include<queue>
using namespace std;

class Queue
{
    int *a;
    int n;
    int cs;
    int f,e;

    public:
    Queue(int s=5)
    {
        a=new int[s];
        s=n;
        f=0;
        e=n-1;
        cs=0;
    }

    void push(int d)
    {
        if (cs<n)
        {
            e=(e+1)%n;
            a[e]=d;
            cs++;
        }
        else
        {
            cout<<"overflow"<<endl;
        }
    }

    void pop()
    {
        if (cs>0)
        {
            f=(f+1)%n;
            cs--;
        }
        else
        {
            cout<<"underflow"<<endl;
        }
    }

    int size()
    {
        return cs;
    }

    int front()
    {
        return a[f];
    }

    bool empty()
    {
        return cs==0;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}