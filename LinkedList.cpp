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

void InsertNodeMid(node* &head, node* &tail, int pos, int d)
{
    node *temp=head;
    for (int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    node *n=new node(d);
    n->next=temp->next;
    temp->next=n;
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

    InsertNodeMid(head,tail,3,17);

    printLL(head);

    cout<<"Length of the LinkedList is "<<lengthLL(head)<<endl;

    return 0;
}