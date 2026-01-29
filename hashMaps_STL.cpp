#include<iostream>
#include<unordered_map>
#include<map>   //for ordered map
using namespace std;

int main()
{
    map<string,int> h;   //always sorted     TC:O(log n)
    //unordered_map<string,int> h;       TC:O(1)

    h.insert(make_pair("mango",100));
    h.insert({"kiwi",50});
    h["apple"]=120;

    //h["apple"]=100; //update

    h["pineapple"]=60;
    h["banana"]=80;

    //printing hashmap : for unorder_map only and not for ordered_map

    /*
    for (int i=0;i<h.bucket_count();i++)
    {
        cout<<i<<":";

        for (auto it=h.begin(i);it!=h.end(i);it++)
        {
            cout<<"("<<(*it).first<<", "<<(*it).second<<")"; 
        }

        cout<<endl;
    }
    */

    //printing hashmap : for unorder_map only and for ordered_map, works for both

    //for (pair<string,int> p : h)
    for  (auto p : h)
    {
        cout<<p.first<<", "<<p.second<<endl;
    }

    return 0;
}