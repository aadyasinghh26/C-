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

int lengthLL(node *head)
{
    int count=0;
    while (head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

void bubbleSort(node* &head)
{
    int len=lengthLL(head);
    for (int i=0;i<len;i++)
    {
        node *c=head, *p=NULL, *n;
        while (c!=NULL and c->next!=NULL)
        {
            n=c->next;
            if (c->data > n->data)     //swapping hogi
            {
                if (p==NULL)   //head change hoga
                {
                    c->next=n->next;
                    n->next=c;
                    head=p=n;
                }
                else         //head change nahi hoga
                {
                    c->next=n->next;
                    n->next=c;
                    p->next=n;
                    p=n;
                }
            }
            else          //no swapping
            {
                p=c;
                c=n;;
            }
        }
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

int main()
{
    node *head=NULL, *tail=NULL;
    InsertNodeLast(head,tail,5);
    InsertNodeLast(head,tail,1);
    InsertNodeLast(head,tail,3);
    InsertNodeLast(head,tail,2);
    InsertNodeLast(head,tail,4);

    printLL(head);

    bubbleSort(head);
    printLL(head);

    return 0;
}