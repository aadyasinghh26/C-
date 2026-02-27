#include<iostream>
#include<unordered_map>
using namespace std;

class node
{
    public:
    char ch;
    bool isEnd;
    unordered_map<char, node*> h;

    node(char c)
    {
        ch=c;
        isEnd=false;
    }
};

class Trie
{
    node *root;
    public:
    Trie()
    {
        root=new node('\0');
    }

    void insert(char *a)      //word ko insert kara
    {
        node *temp=root;
        for (int i=0;a[i];i++)
        {
            char ch=a[i];       //ch mei ek ek karke characters aare word ke

            //agar vo character nahi h toh insert karoge 
            if (temp->h.count(ch)==0)
            {
                node *n=new node(ch);
                temp->h[ch]=n;
            }

            //else sirf jaana h uss par
            temp=temp->h[ch];
        }
         temp->isEnd=true;    //last waale ko true kardia
    }

    bool search(char *a)
    {
        node *temp=root;
        for (int i=0;a[i];i++)
        {
            char ch=a[i];

            if (temp->h.count(ch)==0) return false;     //agar temp ke hashmap mei vo character nahi h toh return false

            temp=temp->h[ch];
        }
        return temp->isEnd;
    }
};

int main()
{
    Trie t;
    t.insert("Hello");
    t.insert("Hell");
    t.insert("Coder");
    t.insert("Code");
    t.insert("Coding");

    while (1)
    {
        char word[1000];
        cin>>word;

        if (t.search(word))
        {
            cout<<"present";
        }
        else
        {
            cout<<"not present";
        }
    }
    return 0;
}