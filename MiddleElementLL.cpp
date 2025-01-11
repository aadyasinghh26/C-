#include<iostream>
using namespace std;

//without using the length of the linked list

class node
{
    public:
    int data;
    node *next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void InsertNodeFront(node* &head, node* &tail, int d)
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

node *mid(node *head)
{
    node *s=head;
    node *f=head->next;
    
    while (f!=NULL and f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
    }
    return s;
}

void printLL(node *temp)
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
    node *head=NULL, *tail=NULL;

    InsertNodeFront(head,tail,1);
    InsertNodeFront(head,tail,2);
    InsertNodeFront(head,tail,3);
    InsertNodeFront(head,tail,4);
    InsertNodeFront(head,tail,5);
    InsertNodeFront(head,tail,6);

    printLL(head);

    node *ans=mid(head);
    cout<<"Middle element is "<<ans->data<<endl;

    return 0;
}