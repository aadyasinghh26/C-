#include<iostream>
#include<list>
using namespace std;

int main()
{
    /*
    first way to insert value in pair

    pair <string,int> p;   //pair is an inbuilt func 
    p.first="simran";
    p.second=11;
    */
    
    /*
    second way to insert value in pair
    
    pair<string,int> p;
    p=make_pair("simran",11);
    */

    //third way to insert value in pair
    
    pair<string,int> p={"simran",11};

    cout<<p.first<<", "<<p.second<<endl;

    list<pair<char,char> > l;      //pair ki linkedlist

    //this is called the edge list
    l.push_back({'a','b'});
    l.push_back({'a','c'});
    l.push_back({'a','d'});
    l.push_back({'b','e'});
    l.push_back({'d','e'});

    //for every pair p which belongs to linkedlist l
    for (auto p : l)
    {
        cout<<"("<<p.first<<", "<<p.second<<")"<<"-->";
    }
    cout<<endl;

}