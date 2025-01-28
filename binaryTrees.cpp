#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *right, *left;

    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

node *buildTree()
{
    int data;
    cin>>data;

    if (data==-1) return NULL;
    else
    {
        node *root=new node(data);
        root->left=buildTree();
        root->right=buildTree();
        return root;
    }
}

void preOrder(node *root)
{
    if (!root) return;
    else
    {
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (!root) return;
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (!root) return;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    node *root=buildTree();

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    return 0;
}