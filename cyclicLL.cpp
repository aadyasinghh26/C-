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

void breakCycle(node *head, node *f)
{
    node *s=head, *fp=head;      //previous pointer for f
    while (fp->next!=f)
    {
        fp=fp->next;
    }

    while (f!=s)
    {
        fp=f;
        f=f->next;
        s=s->next;
    }
    fp->next=NULL;
}

bool isCyclic(node *head)
{
    node *f=head, *s=head;
    while (f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;

        if (f==s)
        {
            //cout<<"cyclic point is:"<<f->data<<endl;
            breakCycle(head,f);
            return true;
        }
    }
    return false;
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
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,2);
    InsertNodeLast(head,tail,3);
    InsertNodeLast(head,tail,4);
    InsertNodeLast(head,tail,5);
    InsertNodeLast(head,tail,6);
    InsertNodeLast(head,tail,7);
    InsertNodeLast(head,tail,8);

    printLL(head);

    tail->next=head->next->next;
    if (isCyclic(head))
    {
        cout<<"cyclic it is"<<endl;
        printLL(head);
    }
    else
    {
        cout<<"not cyclic"<<endl;
        printLL(head);
    }

    return 0;
}