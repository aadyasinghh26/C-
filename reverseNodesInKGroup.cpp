//leetcode question

#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
    ListNode *reverse(ListNode *head,int k)
    {
        ListNode *c=head, *p=NULL, *n;
        for (int i=0;i<k;i++)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *og, *pT=NULL;
        ListNode *temp=head;
        
        while (temp)
        {
            //to ensure ki memory leak na ho
            int i=0;
            while (i<k and temp)
            {
                temp=temp->next;
                i++;
            }

        if (i==k)    //to ensure there are k nodes available to reverse
        {
            ListNode *nH=reverse(head,k);
            if (og==NULL) og=nH;
            if (pT) pT->next=nH;
            pT=head;
            head->next=temp;
            head=temp;
        }
    }
    return og;
}

};

int main()
{
    return 0;
}
