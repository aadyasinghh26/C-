#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *left, *right;

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
        preOrder(root->left);
        preOrder(root->right);
        cout<<root->data<<" ";
    }
}

int height(node *root)
{
    if (!root) return 0;
    else
    {
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right) + 1;
    }
}

int count(node *root)
{
    if (!root) return 0;
    
    return count(root->left) + count(root->right) + 1;
}

int diameter(node *root)
{
    if (!root) return 0;
    else
    {
        //op1 via root
        int op1=height(root->left) + height(root->right);

        //op2 LST 
        int op2=diameter(root->left);

        //op3 RST
        int op3=diameter(root->right);

        return max(op1,max(op2,op3));
    }
}

//FAST DIAMETER (IN O(n))
class Pair
{
    public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root)
{
    Pair p;
    //base case
    if (!root)
    {
        p.height=p.diameter=0;
        return p;
    }

    //recursive case
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);

    int op1=left.height + right.height;
    int op2=left.diameter;
    int op3=right.diameter;

    p.diameter=max(op1,max(op2,op3));
    p.height=max(left.height , right.height) + 1;
    return p;
}


int main()
{
    node *root=buildTree();

    cout<<"PREORDER of the tree is:";
    preOrder(root);
    cout<<endl;

    cout<<"INORDER of the tree is:";
    inOrder(root);
    cout<<endl;

    cout<<"POSTORDER of the tree is:";
    postOrder(root);
    cout<<endl;

    cout<<"HEIGHT of the tree is:"<<height(root)<<endl;

    cout<<"NODES:"<<count(root)<<endl;

    cout<<"DIAMETER:"<<diameter(root)<<endl;

    Pair ans=fastDiameter(root);
    cout<<"FAST DIAMETER:"<<ans.diameter<<endl;
    cout<<"FAST HEIGHT:"<<ans.height<<endl;

    return 0;
}