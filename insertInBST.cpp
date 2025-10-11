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

node *insertInBST(node *root, int data)
{
    //base case
    if (!root)
    {
        root=new node(data);
        return root;
    }

    //recursive case
    if(data < root->data)
    {
        root->left=insertInBST(root->left,data);
        //insert karne ke baad LST ki root node return karni
    }
    else
    {
        root->right=insertInBST(root->right,data);
        //insert karne ke baad RST ki root node return karni
    }

    return root;
}

node *buildTree()
{
    node *root=NULL;
    int data;
    cin>>data;

    while (data!=-1)
    {
        root=insertInBST(root,data);
        //data ko tree mei insert karega
        //root ko return karega

        cin>>data;
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

    inOrder(root->left);                       //BST ka inOrder is sorted 
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

// 8 3 10 1 6 14 4 7 13 -1
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