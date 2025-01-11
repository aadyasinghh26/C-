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

void DeleteAtFront(node* &head, node* &tail)
{
    if (head==NULL) return;
    else if (head->next==NULL)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        node *temp=head;
        head=head->next;
        delete temp;
    }
}

void DeleteAtLast(node* &head, node* &tail)
{
    if (head==NULL) return;
    else if (head->next==NULL)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        node *temp=head;
        while (temp->next!=tail)
        {
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        temp->next=NULL;
    }
}

void DeleteAtMid(node* &head, node* &tail, int pos)
{
    if (pos==0) DeleteAtFront(head,tail);
    else if (pos>=lengthLL(head) - 1) DeleteAtLast(head,tail);
    else
    {
        node *temp=head;
        for (int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        node *n=temp->next;
        temp->next=n->next;
        delete n;
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

    InsertNodeFirst(head,tail,5);
    InsertNodeFirst(head,tail,6);
    InsertNodeFirst(head,tail,7);
    InsertNodeFirst(head,tail,8);
    InsertNodeFirst(head,tail,9);
    InsertNodeFirst(head,tail,10);

    printLL(head);

    DeleteAtMid(head,tail,3);
    printLL(head);
    
    DeleteAtFront(head,tail);
    printLL(head);

    DeleteAtLast(head,tail);
    printLL(head);

    cout<<"length of linkedlist is:"<<lengthLL(head)<<endl;

    return 0;
}