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

node* mergeLL(node *a, node *b)
{
    //base condition
    if (a==NULL) return b;
    if (b==NULL) return a;

    //recursive condition
    node *nH;       //new head
    if (a->data < b->data)
    {
        nH=a;
        nH->next=mergeLL(a->next,b);
    }
    else
    {
        nH=b;
        nH->next=mergeLL(b->next,a);
    }
    return nH;
}

int main()
{
    node *head=NULL,*tail=NULL, *head1=NULL;
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,3);
    InsertNodeLast(head,tail,5);
    InsertNodeLast(head,tail,7);

    InsertNodeLast(head1,tail,2);
    InsertNodeLast(head1,tail,4);
    InsertNodeLast(head1,tail,6);

    printLL(head);
    printLL(head1);

    head=mergeLL(head,head1);
    printLL(head);

    return 0;
}

