#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node *left , *right;

    node(int d)
    {
        data=d;
        left,right=NULL;
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

void levelOrderPrint(node *root)
{
    queue <node*> q;       //addresses of the node
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *x=q.front();
        q.pop();

        if (x!=NULL)
        {
            cout<<x->data<<" ";
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
        }

        else
        {
            cout<<endl;
            if (!q.empty()) q.push(NULL);
        }
    }

}

int main()
{
    node *root=buildTree();

    cout<<"PREORDER OF THE TREE:";
    preOrder(root);
    cout<<endl;

    cout<<"INORDER OF THE TREE:";
    inOrder(root);
    cout<<endl;

    cout<<"POSTORDER OF THE TREE:";
    postOrder(root);
    cout<<endl;

    levelOrderPrint(root);

    return 0;
}