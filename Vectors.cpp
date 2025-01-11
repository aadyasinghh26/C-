#include<iostream>
#include<vector>
using namespace std;

class Vector
{
    public:
    
    int*a;
    int ms;
    int cs;

    Vector(int s=2)
    {
        ms=s;
        cs=0;
        a=new int[ms];
    }

    void push_back(int d)
    {
        if (cs==ms)
        {
            int*newa=new int[2*ms];
            int new_ms=2*ms;

            for (int i=0;i<ms;i++)
            {
                newa[i]=a[i];
            }
            delete [] a;
            a=newa;
            ms=new_ms;
        }
        a[cs++]=d;
    }

    void pop_back()
    {
        if (cs>0) cs--;
    }

    int size()
    {
        return cs;
    }

    int capacity()
    {
        return ms;
    }

    int operator [] (int i)       //operator overloading
    {
        return a[i];
    }

};

int main()
{
    Vector v;

    for (int i=1;i<=5;i++)
    {
        v.push_back(i);
        cout<<"after inserting "<<i<<" size:"<<v.size()<<" capacity:"<<v.capacity()<<endl;
    }

    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}