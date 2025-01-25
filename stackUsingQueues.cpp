#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Stack
{
    queue <int> q1,q2;
    public:

    void push(int d)
    {
        if (!q2.empty()) q2.push(d);
        else q1.push(d);
    }

    void pop()
    {
        if (!q1.empty())
        {
            while (q1.size()>1)
            {
                int f=q1.front();
                q2.push(f);
                q1.pop();
            }
            q1.pop();
        }
        else
        {
            while (q2.size()>1)
            {
                int f=q2.front();
                q1.push(f);
                q2.pop();
            }
            q2.pop();
        }
    }

    int top()
    {
        if (!q1.empty())
        {
            while (q1.size()>1)
            {
                int f=q1.front();
                q2.push(f);
                q1.pop();
            }
            int f=q1.front();
            q2.push(f);
            q1.pop();
            return f;
        }
        else
        {
            while (q2.size()>1)
            {
                int f=q2.front();
                q1.push(f);
                q2.pop();
            }
            int f=q2.front();
            q1.push(f);
            q2.pop();
            return f;
        }
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}