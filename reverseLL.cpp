#include<iostream>
using namespace std;

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

void InsertNodeLast(node* &head, node* &tail, int d)
{
    if (head==NULL)
    {
        node *n=new node(d);
        head=tail=n;
    }
    else
    {
        node *n=new node(d);
        tail->next=n;
        tail=n;
    }
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

void reverseLL(node* &head, node* &tail)
{
    node *p=NULL, *c=head, *n;
    while (c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    swap(head,tail);
}

int main()
{
    node *head=NULL, *tail=NULL;
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,2);
    InsertNodeLast(head,tail,3);
    InsertNodeLast(head,tail,4);
    InsertNodeLast(head,tail,5);

    printLL(head);

    reverseLL(head,tail);
    printLL(head);

    return 0;
}