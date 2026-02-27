#include<iostream>
#include<climits>
using namespace std;

class node
{
    public:
    node *right, *left;
    int val;

    node()
    {
        left=right=NULL;
    }
};

class Trie
{
    node *root;
    public:

    Trie()
    {
        root=new node();
    }

    void insert(int num)
    {
        node *temp=root;
        for (int i=30;i>=0;i--)
        {
            if ((num & (1<<i)) == 0)
            {
                if (!temp->left) temp->left=new node();

                temp=temp->left;
            }
            else
            {
                if (!temp->right) temp->right=new node();

                temp=temp->right;
            }
        }
        temp->val=num;
    }

    int findXOR(int num)
    {
        node *temp=root;

        for (int i=30;i>=0;i--)
        {
            if ((num & (1<<i)) == 0)
            {
                if (temp->right) temp=temp->right;
                else temp=temp->left;
            }
            else
            {
                if (temp->left) temp=temp->left;
                else temp=temp->right;
            }
        }

        return (num ^ temp->val);
    }

    int maxXORpair(int *a,int n)
    {
        int max_ans=INT_MIN;
        
        for (int i=0;i<n;i++)
        {
            insert(a[i]);
            int ans=findXOR(a[i]);
            max_ans=max(max_ans,ans);
        }
        return max_ans;
    }
};

int main()
{
    int a[]={1,2,3,5};
    int n=sizeof (a) / sizeof (int);

    Trie t;
    cout<<t.maxXORpair(a,n)<<endl;

    return 0;
}