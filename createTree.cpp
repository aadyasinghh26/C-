#include<iostream>
#include<queue>

using namespace std;

class node
{
    public:
    int data;
    node *left, *right;

    node(int d)
    {
        data=d;
        left,right=NULL;
    }
};

/*node *buildTree()
{
    int data;
    cin>>data;

    if (data==-1) return NULL;

    node *root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
} */
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

void levelOrderPrint(node *root)
{
    queue<node *>q;
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

int pre[]={8,10,1,6,4,7,3,14,13};
int k=0;

node*createTree(int *in, int s,int e)
{
    if (s>e) return NULL;
    
    node *root=new node(pre[k]);
    k++;

    int i;
    for (int j=s;j<=e;j++)
    {
        if (in[j]==root->data)
        {
            i=j;
            break;
        }
    }

    root->left=createTree(in,s,i-1);
    root->right=createTree(in,i+1,e);
    return root;
}

int main()
{
    //node *root=buildTree();

    int in[]={1,10,4,6,7,8,3,13,14};
    int n=sizeof(in)/sizeof(int);
    node *root=createTree(in,0,n-1);

    cout<<"PREORDER OF THE TREE:";
    preOrder(root);
    cout<<endl;

    cout<<"INORDER OF THE TREE";
    inOrder(root);
    cout<<endl;

    cout<<"POSTORDER OF THE TREE:";
    postOrder(root);
    cout<<endl;

    levelOrderPrint(root);
}

