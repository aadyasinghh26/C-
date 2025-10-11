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
        right=left=NULL;
    }

};

node *insertInBST(node *root, int data)
{
    //base case
    if (!root)
    {
        root=new node(data);
        return root;
    }

    //recursive case
    if (data<root->data)
    {
        root->left=insertInBST(root->left,data);
    }
    else
    {
        root->right=insertInBST(root->right,data);
    }
    return root;
}

void preOrder(node *root)
{
    if (!root) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (!root) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (!root) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printRange(node *root, int k1, int k2)
{
    if (!root) return;

    if (root->data>k1 and root->data<k2)
    {
        cout<<root->data<<" ";
    }
    printRange(root->left,k1,k2);
    printRange(root->right,k1,k2);
}

node *search(node *root, int key)
{
    if (!root) return NULL;

    if (root->data==key)   return root;
    if (key<root->data) return search(root->left,key);
    else
    {
        return search(root->right,key);
    }
}

node *buildTree()
{
    node *root=NULL;
    int data;
    cin>>data;

    while (data!=-1)
    {
        root=insertInBST(root,data);
        //data ko tree mei insert karenge
        //root node return hoga

        cin>>data;
    }
    return root;
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

    cout<<"In between the ranges ";
    printRange(root,5,10);
    cout<<endl;

    node *ans=search(root,10);
    if (ans) cout<<"Key found "<<ans->data<<endl;
    else cout<<"Key not found"<<endl;

    return 0;
}

//8 3 10 1 6 14 4 7 13 -1
