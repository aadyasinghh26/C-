#include<iostream>
#include<queue>
using namespace std;

//everything from class Pair till the end of Comparator is not needed because there is an inbuilt template func

/*
template typename T, typename U>
class Pair
{
    public:
    T first;
    U second;
};

*/

/*
class Pair
{
    public:
    int first;            //sorting is always done on the basis of the first data member
    string second;
};

*/

/*class Comparator
{
    //Functor
    public:
    bool operator() (Pair &x, Pair &y)
    {
        return x.first>y.first;
        // return x.name>y.name   // will sort according to the names
    }

};
*/

int main()
{
    //priority_queue<Pair, vector<Pair>, Comparator >q;   //Min Heap
    //priority_queue<int, vector<int>, less<int> >q;   //Max Heap

    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>> >q;   //it will sort it according to the first data member by default

    pair<int,string> p;
    p.first=95;
    p.second="Vipin";
    q.push(p);

        q.push({100,"Niyati"});
        q.push({80,"Prateek"});
        q.push({70,"Simran"});
        q.push({85,"Aadeep"});

        while (!q.empty())
        {
            pair<int,string> x=q.top();
            cout<<x.first<<", "<<x.second<<endl;
            q.pop();
        }
        cout<<endl;
        return 0;
}