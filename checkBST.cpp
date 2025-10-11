#include<iostream>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node *right,*left;

    node(int d)
    {
        data=d;
        right=left=NULL;
    }
};

node *insertInBST(node*root, int data)
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

bool isBST(node *root, int mi=INT_MIN, int mx=INT_MAX)
{
    if(!root) return true;

    if (root->data>=mi and root->data<=mx and isBST(root->left, mi, root->data) and isBST(root->right, root->data, mx)) return true;
    else return false;
}

node *buildTree()
{
    node *root=NULL;
    int data;
    cin>>data;

    while (data!=-1)
    {
        root=insertInBST(root,data);
        //data ko tree mei daalenge
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

    if (isBST(root)) cout<<"BST";
    else cout<<"not BST";

    return 0;
}

//8 3 10 1 6 14 4 7 13 -1