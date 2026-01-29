#include<iostream>
#include<list>
using namespace std;

int main()
{
    list <int> l;

    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.push_back(4);

    list <int> :: iterator it;

    for (it=l.begin();it!=l.end();it++)
    {
        cout<< *it<<"-->";
    }
    cout<<"NULL"<<endl;

    //for every data that belongs to linkedlist l
    for (auto data : l)
    {
        cout<<data<<"-->";
    }
    cout<<"NULL"<<endl;

    return 0;
}

