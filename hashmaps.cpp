#include<iostream>
using namespace std;

class node
{
    public:
    
    string key;
    int value;
    node *next;

    node(string &s, int v)        //string is passed by reference to avoid copy constructor
    {
        key=s;
        value=v;
        next=NULL;
    }
};

class hashmap
{
    private:

    int hashFunction(string key)
    {
        int ans=0;
        int mul=1;

        for (int i=0;i<key.size();i++)
        {
            ans+=(key[i] % ts) * mul % ts;
            mul*=37;
            ans%=ts;
            mul%=ts;
        }

        return ans % ts;
    }

    void rehashing()
    {
        node **old_a=a;
        int old_ts=ts;

        cs=0;
        a=new node *[2*ts];      //new big array
        ts=ts*2;

        for (int i=0;i<ts;i++)
        {
            a[i]=NULL;
        }

        for (int i;i<old_ts;i++)
        {
            node *head=old_a[i];
            if (!head) continue;
            while (head)
            {
                string key=head->key;
                int value=head->value;

                insert(key,value);

                head=head->next;
            }
        }

        delete []old_a;
    }

    public:
    node **a;       //array of linked lists
    int ts;
    int cs;

    hashmap(int s=5)
    {
        ts=s;
        a=new node * [ts];   //refer notebook
         for (int i=0;i<ts;i++)
         {
            a[i]=NULL;
         }

         cs=0;        //it will track array mei kitne elements gaye
    }

void insert(string key, int value)
{
    int index=hashFunction(key);

    node *n=new node(key,value);
    n->next=a[index];          //linking the new node at the first
    a[index]=n;
    cs++;

    float load_factor=(cs*1.0)/ts;
    if (load_factor>=0.6)
    {
        rehashing();
    }
}

void print()
{
     for (int i=0;i<ts;i++)
     {
        node *head=a[i];
        cout<<i<<"-->";

        while (head)
        {
            string key=head->key;
            int value=head->value;
            
            cout<<"("<<key<<","<<value<<")";

            head=head->next;
        }
        cout<<endl;
     }
}

};

int main()
{
    hashmap h;

    h.insert("mango",100);
    h.insert("kiwi",20);
    //h.insert("banana",50);

    h.print();

    return 0;
}