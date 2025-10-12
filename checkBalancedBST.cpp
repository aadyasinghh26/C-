#include<iostream>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node *right,*left;

    node (int d)
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

class Pair
{
    public:
    int height;
    bool isBalanced;
};

Pair isBalanced(node *root)
{
    Pair p;

    //base case
    if (!root)
    {
        p.height=0;
        p.isBalanced=true;
        return p;
    }

    //recursive case
    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);

    p.height=max(right.height,left.height)+1;

    if (abs(left.height-right.height)<=1 and left.isBalanced and right.isBalanced) p.isBalanced=true;
    else p.isBalanced=false;
    return p;
}

node *buildTree()
{
    node *root=NULL;
    int data;
    cin>>data;

    while (data!=-1)
    {
        root=insertInBST(root,data);
        //data ko root mei insert karega
        //root node ko return karega

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

    Pair p=isBalanced(root);
    if (p.isBalanced) cout<<"Balanced";
    else cout<<"Not balanced";

    return 0;
}

//8 3 10 1 6 14 4 7 13 9 -1