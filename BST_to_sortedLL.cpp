#include<iostream>
#include<climits>
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
    if (!root)
    {
        root=new node(data);
        return root;
    }

    if (data<root->data) root->left=insertInBST(root->left,data);
    else root->right=insertInBST(root->right,data);
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

class LinkedList
{
    public:
    node *head,*tail;
};

LinkedList BSTtoLL(node *root)
{
    LinkedList l;          //it has two objects - head and tail
    //base case
    if (!root)
    {
        l.head=l.tail=NULL;
        return l;
    }

    //recursive case
    if (root->left and root->right)
    {
        LinkedList left=BSTtoLL(root->left);   //convert LST to LL
        LinkedList right=BSTtoLL(root->right);  //covert RST to LL

        left.tail->right=root;
        root->right=right.head;
        l.head=left.head;
        l.tail=right.tail;

        return l;
    }
    else if (!root->left and root->right)
    {
        LinkedList right=BSTtoLL(root->right);

        l.head=root;
        root->right=right.head;
        l.tail=right.tail;

        return l;
    }
    else if (root->left and !root->right)
    {
        LinkedList left=BSTtoLL(root->left);

        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }
    else
    {
        l.head=l.tail=root;
        return l;
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
        //data ko tree mei daalega
        //root return karega

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

    LinkedList ans=BSTtoLL(root); //stored in ans
    node *head=ans.head;      //ans.head is the starting element
    while (head)
    {
        cout<<head->data<<"-->";
        head=head->right;
    }
    cout<<"NULL"<<endl;

    return 0;
}

//8 3 10 1 6 14 4 7 13 -1