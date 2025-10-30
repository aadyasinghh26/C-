#include<iostream>  //jab -1 aagaya tab tak ke top k elements print karwane h
#include<queue>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> >h)
{
    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;
}

int main()
{
    priority_queue<int, vector<int>, greater<int> >h;   //min heap
    int k=3;
    int count=0;

    while (1)
    {
        int data;
        cin>>data;
    

    if (data==-1)
    {
        printHeap(h);
        continue;
    }

    if (count<k)
    {
        h.push(data);
        count++;
    }
    else
    {
        if (h.top()<data)
        {
            h.pop();
            h.push(data);
        }
    }
}

    return 0;
}

// we are using min heap cause we have to remove smallest element and print the largest k elements

