#include<iostream>
#include<vector>
using namespace std;

#define pb push_back

class Minheap
{
    private:
    void heapify(int i)
    {
        int left=2*i;
        int right=2*i +1;
        int mi=i;
        
        if (left<v.size() and v[left]<v[mi])
        {
            mi=left;
        }
        
        if (right<v.size() and v[right]<v[mi])
        {
            mi=right;
        }
        
        if (i!=mi)                    //this is the base case and heapify mei base case niche aata h
        {
            swap(v[i],v[mi]);
            heapify(mi);             // ??         //after swapping mi with i, mi gets unbalanced
        }
    }

    public:
    vector<int> v;

    Minheap()
    {
        v.pb(-1);             // ??             //This inserts a dummy value -1 at the 0th index of the vector. So: v[0] = -1 is just a placeholder, not part of the actual heap
    }

    void push(int data)
    {
        v.pb(data);

        int c=v.size()-1;
        int p=c/2;               //parent is at child/2 position

        while (p>0 && v[p]>v[c])
        {
            swap(v[p],v[c]);
            c=c/2;
            p=p/2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);                 // ??         //after popping up the first element, the next elements which is at the first position is now unbalanced
    }

    bool empty()
    {
        return v.size()==1;             // ??     //counts the dummy  at v[0]
    }
};

int main()
{
    Minheap h;

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