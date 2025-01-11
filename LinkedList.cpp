#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void InsertNodeLast(node* &head, node* &tail, int d)
{
    if (head==NULL)
    {
        node *n = new node(d);
        head=tail=n;
    }
    else
    {
        node *n = new node(d);
        tail->next=n;
        tail=n;
    }
}

void InsertNodeFirst(node* &head, node* &tail, int d)
{
    if (head==NULL)
    {
        node *n=new node(d);
        head=tail=n;
    }
    else
    {
        node *n=new node(d);
        n->next=head;
        head=n;
    }
}

void printLL(node *temp)        //temp pointer
{
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *head=NULL , *tail=NULL;       //agar main mei change karna h toh use by reference or else by value
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,2);
    InsertNodeLast(head,tail,3);
    InsertNodeLast(head,tail,4);
    
    InsertNodeFirst(head,tail,5);
    InsertNodeFirst(head,tail,6);
    InsertNodeFirst(head,tail,7);

    printLL(head);

    return 0;
}