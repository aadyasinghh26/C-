#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Queue
{
    int *a;
    int n;
    int cs;
    int e,f;

    public:
    Queue(T s=5)
    {
        a=new int[5];
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

    T front()
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
    //Queue <int> q;
    Queue <char> q;
    
    //q.push(1);
    //q.push(2);
    //q.push(3);
    //q.push(4);

    q.push('A');
    q.push('B');
    q.push('C');
    q.push('D');

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
