#include<iostream>
#include<set>
using namespace std;

int main()
{
    set <int> s;
                             //duplicate values are not allowed in sets
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(1);

    //print (way 1)
    for (auto e : s)
    {
        cout<<e<<" ";       //by default set prints the sorted order
    }
    cout<<endl;

    //print (way 2)
    while (!s.empty())               //set ko khaali karke print karre
    {
        auto x=s.begin();   //address h uska jo set mei pehle pada hai
        cout<<*x<<" ";   //address is passed
        s.erase(x);
    }
    cout<<endl;

    //inserting a pair inside set
    set<pair<int, string> > s1;          
    s1.insert({100,"mango"}); 
    s1.insert({120,"apple"});
    s1.insert({80,"guava"});
    s1.insert({90,"orange"});

    /*
    while (!s1.empty())             //pehle argument ke basis par sort hoga
    {
        auto x=s1.begin();
        cout<<(*x).first<<","<<(*x).second<<endl;
        s1.erase(x);
    }
    cout<<endl;
    */

    //inorder to update value in set, we have to delete the previous value and then insert the new one again

    auto add=s1.find({100,"mango"});
    if (add != s1.end())     //last mei na pahunch gaye
    {
        s1.erase(add);
    }

    s1.insert({150,"mango"});

    while(!s1.empty())
    {
        auto x=s1.begin();
        cout<<(*x).first<<","<<(*x).second<<endl;
        s1.erase(x);
    }
    cout<<endl;

    return 0;
}

