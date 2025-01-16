#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node (int d)
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

node *mergeLL(node *a, node *b)
{
    //base condition
    if (a==NULL) return b;
    if (b==NULL) return a;

    //recursive condition
    node *nh;
    if (a->data < b->data)
    {
        nh=a;
        nh->next=mergeLL(a->next,b);
    }
    else
    {
        nh=b;
        nh->next=mergeLL(a,b->next);
    }
    return nh;
}

//merge sort
node *mergeSort(node *head)
{
    //base condition
    if (head==NULL or head->next==NULL) return head;

    //recursive condition
    node *a=head;
    node *m=mid(head);
    node *b=m->next;
    m->next=NULL;

    a=mergeSort(a);
    b=mergeSort(b);

    node *nh=mergeLL(a,b);
    return nh;
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

    InsertNodeLast(head,tail,5);
    InsertNodeLast(head,tail,2);
    InsertNodeLast(head,tail,4);
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,3);

    printLL(head);

    head=mergeSort(head);
    printLL(head);

    return 0;
}